// Trees6presentation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>

class BinaryNode {
public:
    BinaryNode* left_child = nullptr;
    BinaryNode* right_child = nullptr;
    BinaryNode(std::string t) : text(t) {};
    void Print(bool with_new_line = false) {
        std::cout << text + (with_new_line ? "\n" : "");
    };
    void TraverseInorder();
    void TraversePreorder();
    void TraversePostorder();
    void AddNode(BinaryNode* node);
//  void SearchNode(std::string text);
//  static void DeleteNode();
//  void TraverseDepthFirst();
private:
    std::string text;
};

//нахождение операции с наим приоритетом
/*
BinaryNode* FillTree(string expr) {
    if (expr.length() == 1)//Если длина подстроки равна 1, то надо создать новую вершину с числовым  или буквенным значением
        return new BinaryNode(expr);

    int k = FindLastLowerOperation(expr);// k-последняя операция с наим приоритетом
    BinaryNode* root = new BinaryNode(string(1, expr[k]));//узел, содержащий знак этой операции, и рекурсивно сформировать левого и правого потомка
    //на след шаге

    string lexpr = expr.substr(0, k);//Левый потомок определяется подстрокой строки от 0 до k - 1.
    string rexpr = expr.substr(k + 1, expr.length() - k);//Правый потомок определяется по подстроке от k + 1 до N

    if (lexpr.length())
        root->left_child = FillTree(lexpr);
    if (rexpr.length())
        root->right_child = FillTree(rexpr);
    return root;
}*/

/*float CalculateExpr(BinaryNode* root) {
    if (IsOperator(root->getText()[0])) {
        if (IsOperator(root->left_child->getText()[0])) {
            float value = CalculateExpr(root->left_child);
            root->left_child->setText(to_string(value));
            root->left_child->DeleteChildren();
        }
        if (IsOperator(root->right_child->getText()[0])) {
            float value = CalculateExpr(root->right_child);
            root->right_child->setText(to_string(value));
            root->right_child->DeleteChildren();
        }
        return DoOperation(
            stof(root->left_child->getText()),
            stof(root->right_child->getText()),
            root->getText()[0]
        );
    }
    else {
        return stof(root->getText());
    }      
}*/




/*int FindLastLowerOperation(string expr) {
    int k = -1;
    for (int i = 0; i < expr.length(); i++) {
        char s = expr[i];
        if (IsOperator(s)) {
            if (k < 0) {
                k = i;
            }
            else {
                if (CompareOperators(s, expr[k])) {
                    k = i;
                }
            }
        }
    }
    return k;
}*/

//прямой обход
void BinaryNode::TraversePostorder() {
    if (this->left_child)
        this->left_child->TraversePostorder();

    if (this->right_child)
        this->right_child->TraversePostorder();

    this->Print();
}

//симметричный обход
void BinaryNode::TraversePreorder() {
    this->Print();

    if (this->left_child)
        this->left_child->TraversePreorder();

    if (this->right_child)
        this->right_child->TraversePreorder();
}

//обход в обратном порядке
void BinaryNode::TraverseInorder() {
    if (this->left_child)
        this->left_child->TraverseInorder();

    this->Print();

    if (this->right_child)
        this->right_child->TraverseInorder();
}

void BinaryNode::AddNode(BinaryNode* node) {
    if (node->text < this->text) {
        if (!this->left_child)
            this->left_child = node;
        else
            this->left_child->AddNode(node);
    }
    else {
        if (!this->right_child)
            this->right_child = node;
        else
            this->right_child->AddNode(node);
    }
}

/*static BinaryNode* BinaryNode::DeleteNode(BinaryNode* root, std::string text) {
    if (!root)
        return root;

    if (text < root->text)
        root->left_child = DeleteNode(
            root->left_child, text);
    else if (text > root->text)
        root->right_child = DeleteNode(
            root->right_child, text);
    else {
        // ...
    }
    return root;
}*/


/*BinaryNode* BinaryNode::SearchNode(std::string text) {
    if (this->text == text)
        return this;

    if (this->text > text)
        if (this->left_child)
            return this->left_child->SearchNode(text);
        else
            return nullptr;
    else
        return this->right_child
        ? this->right_child->SearchNode(text)
        : nullptr;
}*/


//обход в ширину
/*void BinaryNode::TraverseDepthFirst() {
    queue<BinaryNode*> children;
    children.push(root);

    while (!children.empty()) {
        BinaryNode* node = children.front();
        children.pop();

        node->Print();

        if (node->left_child)
            children.push(node->left_child);
        if (node->right_child)
            children.push(node->right_child);
    }
}*/


int main()
{
    setlocale(LC_ALL, "Rus");

    BinaryNode* root = new BinaryNode("A");

    BinaryNode* node1_1 = new BinaryNode("B");
    BinaryNode* node1_2 = new BinaryNode("C");
    BinaryNode* node2_1 = new BinaryNode("D");
    BinaryNode* node2_2 = new BinaryNode("E");

    root->left_child = node1_1;
    root->right_child = node1_2;
    node1_1->left_child = node2_1;
    node1_2->right_child = node2_2;

    std::cout << "Вершина: ";
    root->Print();

    std::cout << "\n" << "Прямой обход дерева: ";
    root->TraversePreorder();
    
    std::cout << "\n" << "Симметричный обход дерева: ";
    root->TraverseInorder();

    std::cout << "\n" << "Обход в обратном порядке: ";
    root->TraversePostorder();

    BinaryNode* new_node = new BinaryNode("F");
    root->AddNode(new_node);

    std::cout << "\n" << "После добавления: ";
    root->TraverseInorder();

//  root->SearchNode(");
//  root->TraverseInorder();

/*  std::cout << "\n" << "Обход в ширину: ";
    root->TraverseDepthFirst();
    root->Print();
*/

    return 0;
}

