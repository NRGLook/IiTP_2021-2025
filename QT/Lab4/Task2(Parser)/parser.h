#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <QVector>
#include "_stack.h"
#include <mystring.h>
#include <QString>
#include "_pair.h"
class parser {
private:

    std::string parse_token() {


        while (isspace(*input)) {

            if (*input == '\n')
                ++line;

            ++input;
        }

        if (*input == '{')
            skobki.push('{');

        else if (*input == '}')
            skobki.pop();

        static const std::string tokens[] =
        {
            "int", "double", "char", "short", "bool", "unsigned", "string", "void", "QVector",

            "class", "struct",

            "cin", "std::cin", "=", "++", "--", "+=", "-=", "/=", "*=", "push_back", "erase", "insert",

            "if",

            "while", "const", "!="
        };

        for (auto& cur : tokens)

            if (!strncmp(input, cur.c_str(), strlen(cur.c_str()))) {

                input += strlen(cur.c_str());

                return cur;
            }

        ++input;

        return "";
    }

    const char* input;

    std::string token;

    QVector< pair<std::string, std::string> >  shorts, ints, unsigneds, doubles, chars, strings,  bools, QVectors;

    QVector<pair <std::string, pair<std::string, std::string>> > pointers;

    std::string ptr_type;

    unsigned line = 1;

    QVector< pair<unsigned, std::string> > functions;

    std::string prototype;


    unsigned classes = 0, structs = 0, arrs = 0,
        overloaded = 0, local_variables = 0, ifs = 0;

    Stack<char> skobki;


    QVector<std::string> consts;

    QString info;
    void add_func() {

        while (*input != ')') {

            if (*input == '\n')
                ++line;

            prototype.push_back(*input++);
        }

        prototype.push_back(*input);

        std::string actual_prototype = prototype;

        unsigned i = 0;
        int deleted = 0;

        while (actual_prototype[i++] != '(');

        for (i; actual_prototype[i] != '\0'; i += 2) {

            deleted = 0;

            while (isspace(actual_prototype[i]) && actual_prototype[i] != '\0')
                ++i;


            if (actual_prototype[i] == '\0')
                break;


            while (!isspace(actual_prototype[i]) && actual_prototype[i] != '\0'
                && actual_prototype[i] != ',')
                ++i;


            if (actual_prototype[i] == '\0')
                break;


            if (actual_prototype[i] == ',')
                continue;


            while (actual_prototype[i] != ',' && actual_prototype[i] != ')') {

                actual_prototype.erase(i, 1);

                ++deleted;
            }

            if (actual_prototype[i] == ')')
                break;

            ++i;
            i -= deleted;
        }

        ++input;

        bool unique = true;

        for (unsigned i = 0; i < functions.size(); ++i)

            if (actual_prototype == functions[i].second) {
                unique = false;
                break;
            }

        if (unique)
            functions.push_back(pair<unsigned, std::string>(line, actual_prototype));

    }

    void get_overloaded() {

        QVector< pair<unsigned, std::string> > overloaded_func;

        for (unsigned i = 0; i < functions.size(); ++i) {

            std::string prototpe;

            unsigned j = 0;

            while (functions[i].second[j] != '(') {

                prototpe.push_back(functions[i].second[j]);

                ++j;
            }

            overloaded_func.push_back(pair<unsigned, std::string>(functions[i].first, prototpe));
        }

        QVector<int> seen;

        QVector<unsigned> lines;

        seen.resize(overloaded_func.size());

        for (unsigned i = 0; i < overloaded_func.size(); ++i) {

            if (seen[i] == 0) {
                unsigned count = 0;
                for (unsigned j = i; j < overloaded_func.size(); ++j)

                    if (overloaded_func[j].second == overloaded_func[i].second) {

                        count += 1;

                        seen[j] = 1;

                        lines.push_back(functions[j].first);
                    }

                if (count > 1) {

                    ++overloaded;

                }
            }
        }

        info += "\n\nКоличество перегруженных функций:\t"; info += QString::number(overloaded); info += '\n';

        if (overloaded) {

        info += "\nНомера строк, на которых встречалась перегруженная функция или её прототип:\n";

        for (unsigned i = 0; i < lines.size(); ++i) {
            info += QString::number(lines[i]);
            info += '\t';
        }
        }

    }

    void add_ptr() {

        while (isspace(*input)) {

            if (*input == '\n')
                ++line;

            ++input;
        }

        std::string variable_name;

        while (*input != ' ' && *input != '='
            && *input != ';' && *input != ',' && *input != '\0' && *input != ')') {

            if (*input == '[') {

                while (*input != ']') {

                    if (*input == '\n')
                        ++line;

                    ++input;
                }

                ++arrs;

                break;
            }

            variable_name.push_back(*input++);
        }

        std::string default_value;

        while (*input != 'N' && *input != 'n' && *input != '&'
            && *input != ';' && *input != ',' && *input != '\0'
            && *input != '(')
            ++input;

        if (*input == '(') {

            prototype = prototype + ptr_type + std::string(" ") + variable_name + std::string("(");

            ++input;

            add_func();

            return;
        }

        while (*input != ';' && *input != '\0' && *input != ',' && *input != ')') {

            default_value.push_back(*input++);
        }

        std::string isArr = default_value;

        while (!isArr.empty()) {

            if (isArr[0] == '[') {
                ++arrs;
                break;
            }
            isArr.erase(0, 1);
        }

        if (*input == ',') {
            ++input;
            add_ptr();
        }

        if (!skobki.isEmpty())
            ++local_variables;

        pair<std::string, pair<std::string, std::string>> new_ptr;

        new_ptr.first = ptr_type;
        new_ptr.second.first = variable_name;
        new_ptr.second.second = default_value;

        pointers.push_back(new_ptr);

    }

    void add_item(QVector <pair<std::string, std::string>>& variables) {

        while (isspace(*input)) {

            if (*input == '\n')
                ++line;

            ++input;
        }

        if (*input == '*') {

            ++input;

            add_ptr();

            return;
        }

        std::string variable_name;

        while (*input != ' ' && *input != '='
            && *input != ';' && *input != ',' && *input != '\0'
            && *input != ')' && *input != '(') {

            if (*input == '\n')
                ++line;

            if (*input == '[') {

                while (*input != ']') {

                    if (*input == '\n')
                        ++line;

                    ++input;
                }

                ++arrs;

                break;
            }

            variable_name.push_back(*input++);
        }

        if (variable_name.empty())
            return;

        std::string default_value;

        while (!isdigit(*input) && !isalpha(*input)
            && *input != ';' && *input != ','
            && *input != '(' && *input != '\0') {

            if (*input == '\n')
                ++line;

            ++input;
        }

        if (*input == '(') {

            prototype = ptr_type + std::string(" ") + variable_name + std::string("(");

            ++input;

            if (variable_name != "main")
                add_func();

            return;
        }


        while (*input != ';' && *input != '\0' && *input != ','
            && *input != ')') {

            if (*input == '\n')
                ++line;

            if (*input != 34 && *input != 39) //номера одинарных и двойных кавычек
                default_value.push_back(*input);

            ++input;
        }

        if (*input == ',') {
            ++input;
            add_item(variables);
        }

        if (!skobki.isEmpty()) {

            ++local_variables;

            info += "\nЛокальная переменная ";
            info += QString(variable_name.c_str());
            info += " находится на ";
            info += QString::number(line);
            info += " строке.\n";
        }

        variables.push_back(pair<std::string, std::string>(variable_name, default_value));

    }

    void add_QVector() {

        while (isspace(*input)) {

            if (*input == '\n')
                ++line;

            ++input;
        }

        std::string name;

        while (*input != ',' && *input != '\0' && *input != ';' && *input != '=')
            name.push_back(*input++);

        if (*input == ',') {

            ++input;

            add_QVector();
        }

        std::string default_value;

        if (*input == '=') {

            bool list = false;

            ++input;

            while (isspace(*input))
                ++input;

            if (*input == '{')
                list = true;

            while (*input != '\0' && *input != ';') {

                if (*input == '\n')
                    ++line;

                if (*input == '}') {

                    list = false;

                    default_value.push_back(*input++);

                }

                else if (*input == ',')

                    if (list)
                        default_value.push_back(*input++);
                    else
                        break;

                else
                    default_value.push_back(*input++);

            }

            if (*input == ',') {

                ++input;

                add_QVector();
            }

        }

        if (!skobki.isEmpty()) {

            ++local_variables;

            info += "\nЛокальная переменная ";
            info += name.c_str();
            info += " находится на ";
            info += QString::number(line);
            info += " строке.\n";
        }

        QVectors.push_back(pair<std::string, std::string>(name, default_value));

    }

    void str_vec_changed(std::string& token) {

        while (!isspace(*input) && *input != ';' && *input != ',') {

            if (*input == '\n')
                ++line;

            --input;
        }

        std::string variable_name;

        ++input;

        while (*input != '.')
            variable_name.push_back(*input++);

        input += token.size();

        ++input;

        info += "\nПеременная\t";
        info += variable_name.c_str();
        info += "\t была изменена на ";
        info += QString::number(line);
        info += " строке.\n";

    }

    void add_if() {

        ++ifs;

        while (*input != ')') {

            if (*input == '\n')
                ++line;

            ++input;
        }

        ++input;

        while (isspace(*input)) {

            if (*input == '\n')
                ++line;

            ++input;
        }

        if (*input == '{') {


            static size_t prev_sz = skobki.size();

            do {

                parse_code();

            } while (skobki.size() != prev_sz);

        }
        else

            while (*input != ';' && *input != '\0')
                parse_code();


        if (ifs) {

            info += "\n\nГлубина встреченного ветвления:\t";
            info += QString::number(ifs);
            info += "\n\n";
        }

        ifs = 0;

    }

    void find_changed(char operation) {

        unsigned back_symbols = 0;

        while (*input != operation) {
            --input;
            ++back_symbols;
        }

        --input; ++back_symbols;

        while (isspace(*input)) {

            if (*input == '\n')
                ++line;

            --input;
            ++back_symbols;
        }

        std::string name;

        while (!isspace(*input) && *input != ',' && *input != ';') {

            --input;
            ++back_symbols;
        }

        ++input; --back_symbols;

        while (!isspace(*input)) {

            name.push_back(*input++);

            --back_symbols;
        }

        input += back_symbols;

        info += "\nПеременная\t";
        info += name.c_str();
        info += "\t была изменена на ";
        info += QString::number(line);
        info += " строке.\n";

        while (*input != ';' && *input != '\0' && *input != ',' && *input != '=')
            ++input;

    }

    void push_const(QVector< pair<std::string, std::string> > &variables, unsigned& sz) {

        while (sz != variables.size()) {

            ++sz;

            consts.push_back(variables[sz - 1].first);
        }

    }

    void push_const_ptr(unsigned& sz) {

        while (sz != pointers.size()) {

            ++sz;

            consts.push_back(pointers[sz - 1].second.first);
        }
    }

    void add_const() {

        while (isspace(*input)) {

            if (*input == '\n')
                ++line;

            ++input;
        }

        unsigned ints_sz = ints.size(),
            doubles_sz = doubles.size(),
            chars_sz = chars.size(),
            strings_sz = strings.size(),
            shorts_sz = shorts.size(),
            unsigneds_sz = unsigneds.size(),
            bools_sz = bools.size(),
            ptr_sz = pointers.size();

        while (*input != '\0' && *input != ';' && *input != '}')
            parse_code();

        if (ints_sz < ints.size())
            push_const(ints, ints_sz);

        else if (doubles_sz < doubles.size())
                push_const(doubles, doubles_sz);

        else if (chars_sz < chars.size())
            push_const(chars, chars_sz);

        else if (strings_sz < strings.size())
            push_const(strings, strings_sz);

        else if (shorts_sz < shorts.size())
            push_const(shorts, shorts_sz);

        else if (unsigneds_sz < unsigneds.size())
            push_const(unsigneds, unsigneds_sz);

        else if (bools_sz < bools.size())
            push_const(bools, bools_sz);

        else if (ptr_sz < pointers.size())
            push_const_ptr(ptr_sz);

    }

    bool is_num(std::string& str) {

        if (str[0] == '-')
            str.erase(0, 1);

        return (isdigit(str[0]));
    }

    void check_while() {

        while (isspace(*input)) {

            if (*input == '\n')
                ++line;

            ++input;
        }

        ++input;

        std::string expr;

        while (*input != ')' && !isspace(*input))
            expr.push_back(*input++);

        if (*input == '\n')
            ++line;

        if (expr == "1" || expr == "0" ||
            expr == "true" || expr == "false" || is_num(expr)) {

            info += "\nОбнаружена логическая ошибка на строке\t";
            info += QString::number(line);
            info += '\n';
        }

        else {

            for (unsigned i = 0; i <consts.size(); ++i)

                if (expr == consts[i]) {

                    info += "\nОбнаружена логическая ошибка на строке\t";
                    info += QString::number(line);
                    info += '\n';

                    break;
                }

        }
    }

    void increment() {

        while (isspace(*input) && *input != '\0') {

            if (*input == '\n')
                ++line;

            ++input;
        }

        std::string name;

        if (*input == ',' || *input == ';' || *input == '\0' || *input == ')') {


            while (!isspace(*input))
                --input;


            ++input;

            while (*input != '+' && *input != '-' && !isspace(*input))
                name.push_back(*input++);

            if (isspace(*input))
                while (*input != '+' && *input != '-')
                    ++input;

            input += 2;
        }
        else {

            while (!isspace(*input) && *input != '\0'
                && *input != ',' && *input != ';' && *input != ')')

                name.push_back(*input++);

        }

        info += "\nПеременная\t";
        info += name.c_str();
        info += "\t была изменена на ";
        info += QString::number(line);
        info += " строке.\n";

    }

    void find_changed_CIN() {

        while (!isalpha(*input) && *input != '_')
            ++input;

        std::string name;

        while (!isspace(*input) && *input != ';' &&
            *input != '\0' && *input != '>' && *input != '=')

            name.push_back(*input++);

        if (*input == '\n')
            ++line;

        if (*input == '>') {

            input += 2;

            find_changed_CIN();
        }

        info += "\nПеременная\t";
        info += name.c_str();
        info += "\t была изменена на ";
        info += QString::number(line);
        info += " строке.\n";

        while (*input != ';' && *input != '\0')
            ++input;
    }

    void parse_code() {

        auto token = parse_token();

        if (token.empty())
            return;

        ptr_type = token;

        if (token == "cin" || token == "std::cin")
            find_changed_CIN();

        else if (token == "!=")
            return;

        else if (token == "push_back" || token == "insert" || token == "erase")
            str_vec_changed(token);

        else if (token == "const")
            add_const();

        else if (token == "if")
            add_if();

        else if (token == "while")
            check_while();

        else if (token == "++" || token == "--")
            increment();

        else if (token == "=")
            find_changed('=');

        else if (token == "*=")
            find_changed('*');

        else if (token == "+=")
            find_changed('+');

        else if (token == "-=")
            find_changed('-');

        else if (token == "/=")
            find_changed('/');

        else if (token == "void")
            add_item(ints);

        else if (token == "int")
            add_item(ints);

        else if (token == "double")
            add_item(doubles);

        else if (token == "char")
            add_item(chars);

        else if (token == "bool")
            add_item(bools);

        else if (token == "unsigned")
            add_item(unsigneds);

        else if (token == "short")
            add_item(shorts);

        else if (token == "string")
            add_item(strings);

        else if (token == "QVector")
            add_QVector();

        else if (token == "class")
            ++classes;

        else if (token == "struct")
            ++structs;

    }


    void show_variables(QVector<pair<std::string, std::string>>& variables) {

        for (unsigned i = 0; i < variables.size(); ++i) {
            info += "\nимя:\t";
            info += variables[i].first.c_str();
            info += "\tбазовое значение:\t";
            info += variables[i].second.c_str();

        }

        info += "\t";
        info += QString::number(variables.size());
        info += '\n';

        putchar('\n');

    }

    void show_ptr() {

        for (unsigned i = 0; i < pointers.size(); ++i) {

            info += "\nТип данных:\t";
            info += pointers[i].first.c_str();
            info += "\tимя:\t";
            info += pointers[i].second.first.c_str();
            info += "\tбазовое значение:\t";
            info += pointers[i].second.second.c_str();

        }

        info += "\t";
        info += QString::number(pointers.size());
        info += '\n';

        putchar('\n');
    }

    void show_func() {

        for (unsigned i = 0; i < functions.size(); ++i) {
            info += '\n';
            info += functions[i].second.c_str();
            info += ';';
        }

        if (!functions.empty())
            get_overloaded();

        info += '\n';

    }

public:
    explicit parser(const char* code) : input(code) {}

    ~parser() = default;

    void parse() {

        while (*input != '\0')
            parse_code();


        info += "\n\short:";
        show_variables(shorts);

        info += "\nint:";
        show_variables(ints);

        info += "\nunsigned:";
        show_variables(unsigneds);

        info += "\ndouble:";
        show_variables(doubles);

        info += "\nchar:";
        show_variables(chars);

        info += "\nstring:";
        show_variables(strings);

        info += "\nbool:";
        show_variables(bools);

        info += "\nQVector:";
        show_variables(QVectors);

        info += "\nУказатели:";
        show_ptr();

        info += "\nПрототипы функций:\n";
        show_func();

        info += "\n\nКоличество классов:\t"; info += QString::number(classes);
        info += "\nКоличество структур:\t"; info += QString::number(structs);
        info += "\nКоличество массивов:\t"; info += QString::number(arrs);
        info += "\nКоличество локальных перемнных: "; info += QString::number(local_variables);

    }

    QString get_info() {
        return info;
    }
};

#endif // PARSER_H
