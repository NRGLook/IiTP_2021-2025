#ifndef MYSTRING_H
#define MYSTRING_H

#include "MyString_global.h"

class MYSTRING_EXPORT MyString {
private:
    char* data;
    size_t sizee;
public:

    void* my_memcpy(void* s1, const void* s2, size_t n);

    void* my_memmove(void* s1, const void* s2, size_t n);

    char* my_strcpy(char* s1, const char* s2);

    char* my_strncpy(char* s1, const char* s2, size_t n);

    char* my_strcat(char* s1, const char* s2);

    char* my_strncat(char* s1, const char* s2, size_t n);

    int my_memcmp(const void* s1, const void* s2, size_t n);

    int my_strcmp(const char* s1, const char* s2) const;

    int my_strcoll(const char* s1, const char* s2);

    int my_strncmp(const char* s1, const char* s2, size_t n) ;

    size_t my_strxfrm(char* s1, const char* s2, size_t n);

    char* my_strtok(char* s1, char s2);

    void* my_memset(void* s, int c, size_t n);

    char* my_strerror(int errnum);

    size_t my_strlen(const char* s) const;

    MyString();

    MyString(const MyString& s);

    MyString(const char* cs);

    MyString(const MyString& s, const size_t& pos, const size_t& n);

    MyString(const char* cs, const size_t& n);

    MyString(const size_t& n, const char& c);

    ~MyString();

    char* getText();

    void setText(char* text);

    size_t getLength() const;

    void setLength(size_t sizee);

    void add(const MyString& text);

    char at(size_t pos) const;

    char back() const;

    char front() const;

    bool compare(const MyString& string) const;

    char operator[](size_t pos);

    void append(MyString& string);

    bool empty();

    void clear();

    void push_back(char q);

    void pop_back();

    size_t capacity();

    size_t size();

    size_t lenght();

    void resize(size_t sizee, char c);

    size_t max_size();

    MyString& assign(const char* cs, const size_t& n);

    MyString& insert(const size_t& pos, const MyString& s);

    MyString& erase(const size_t& pos, const size_t& n);

    MyString& replace(const size_t& pos, const size_t& n, const MyString& s);

    size_t copy(char* cs, const size_t& n, const size_t& pos) const;

    void swap(MyString& s);

    size_t rfind(const char* s2);

    int find(MyString textForFind);

    int find_first_of(MyString textForFind);

    int find_last_of(MyString textForFind);

    int find_first_not_of(MyString textForFind);

    int find_last_not_of(MyString textForFind);


};

MyString operator+(const MyString& string1, const MyString& string2);
bool operator==(const MyString& string1, const MyString& string2);

#endif // MYSTRING_H
