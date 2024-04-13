#include "mystring.h"

void* MyString::my_memcpy(void* s1, const void* s2, size_t n) {
    char* csrc = (char*)s2;
    char* cdest = (char*)s1;

    for (int i = 0; i < n; i++)
        cdest[i] = csrc[i];
}

void* MyString::my_memmove(void* s1, const void* s2, size_t n) {
    char* csrc = (char*)s2;
    char* cdest = (char*)s1;

    char* temp = new char[n];

    for (int i = 0; i < n; i++)
        temp[i] = csrc[i];

    for (int i = 0; i < n; i++)
        cdest[i] = temp[i];

    delete[] temp;
}

char* MyString::my_strcpy(char* s1, const char* s2) {
    if (s1 == NULL) {
        return NULL;
    }
    char* ptr = s1;

    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';
    return ptr;
}

char* MyString::my_strncpy(char* s1, const char* s2, size_t n)
{
    if (s1 == NULL) {
        return NULL;
    }

    char* ptr = s1;

    while (*s2 && n--)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';

    return ptr;
}

char* MyString::my_strcat(char* destination, const char* source)
{
    char* ptr = destination + my_strlen(destination);

    while (*source != '\0') {
        *ptr++ = *source++;
    }

    *ptr = '\0';

    return destination;
}

char* MyString::my_strncat(char* destination, const char* source, size_t num)
{
    char* ptr = destination + my_strlen(destination);

    while (*source != '\0' && num--) {
        *ptr++ = *source++;
    }

    *ptr = '\0';

    return destination;
}

int MyString::my_memcmp(const void* buf1, const void* buf2, size_t count)
{
    if (!count)
        return(0);

    while (--count && *(char*)buf1 == *(char*)buf2) {
        buf1 = (char*)buf1 + 1;
        buf2 = (char*)buf2 + 1;
    }

    return(*((unsigned char*)buf1) - *((unsigned char*)buf2));
}

int MyString::my_strcmp(const char* X, const char* Y) const
{
    while (*X)
    {
        if (*X != *Y) {
            break;
        }

        X++;
        Y++;
    }

    return *(const unsigned char*)X - *(const unsigned char*)Y;
}

int MyString::my_strncmp(const char* s1, const char* s2, size_t n)
{
    while (n && *s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
        --n;
    }
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (*(unsigned char*)s1 - *(unsigned char*)s2);
    }
}

char* MyString::my_strtok(char* s,  char d)
{
    static char* input = NULL;

    if (s != NULL)
        input = s;

    if (input == NULL)
        return NULL;

    char* result = new char[my_strlen(input) + 1];
    int i = 0;

    for (; input[i] != '\0'; i++) {

        if (input[i] != d)
            result[i] = input[i];

        else {
            result[i] = '\0';
            input = input + i + 1;
            return result;
        }
    }

    result[i] = '\0';
    input = NULL;

    return result;
}

void* MyString::my_memset(void* b, int c, size_t len)
{
    int i;
    unsigned char* p = (unsigned char* )b;
    i = 0;
    while (len > 0)
    {
        *p = c;
        p++;
        len--;
    }
    return(b);
}

size_t MyString::my_strlen(const char* str) const
{
    const char* s;
    for (s = str; *s; ++s) ;
    return (s - str);
}


int MyString::my_strcoll(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
    }
    if (*s1 == '\0' && *s2 == '\0') return 0;

    return (*(unsigned char*)s1 - *(unsigned char*)s2);
}


size_t MyString::my_strxfrm(char* s1, const char* s2, size_t n) {

    size_t buf = 0;
    if (s1 == NULL) {
        return NULL;
    }

    char* ptr = s1;

    while (*s2 && n--)
    {
        *s1 = *s2;
        s1++;
        s2++;
        buf++;
    }

    *s1 = '\0';

    return buf;
}

char* MyString::my_strerror(int errnum)
{
    char a[60];
    switch (errnum) {
    default: my_strcpy(a, "Undefined error: 0"); break;
    case 1: my_strcpy(a, "Operation not permitted"); break;
    case 2: my_strcpy(a, "No such file or directory"); break;
    case 3: my_strcpy(a, "No such process"); break;
    case 4: my_strcpy(a, "Interrupted system call"); break;
    case 5: my_strcpy(a, "Input/output error"); break;
    case 6: my_strcpy(a, "Device not configured"); break;
    case 7: my_strcpy(a, "Argument list too long"); break;
    case 8: my_strcpy(a, "Exec format error"); break;
    case 9: my_strcpy(a, "Bad file descriptor"); break;
    case 10: my_strcpy(a, "No child processes"); break;
    case 11: my_strcpy(a, "Resource deadlock avoided"); break;
    case 12: my_strcpy(a, "Cannot allocate memory"); break;
    case 13: my_strcpy(a, "Permission denied"); break;
    case 14: my_strcpy(a, "Bad address"); break;
    case 15: my_strcpy(a, "Block device required"); break;
    case 16: my_strcpy(a, "Device busy"); break;
    case 17: my_strcpy(a, "File exists"); break;
    case 18: my_strcpy(a, "Cross-device link"); break;
    case 19: my_strcpy(a, "Operation not supported by device"); break;
    case 20: my_strcpy(a, "Not a directory"); break;
    case 21: my_strcpy(a, "Is a directory"); break;
    case 22: my_strcpy(a, "Invalid argument"); break;
    case 23: my_strcpy(a, "Too many open files in system"); break;
    case 24: my_strcpy(a, "Too many open files"); break;
    case 25: my_strcpy(a, "Inappropriate ioctl for device"); break;
    case 26: my_strcpy(a, "Text file busy"); break;
    case 27: my_strcpy(a, "File too large"); break;
    case 28: my_strcpy(a, "No space left on device"); break;
    case 29: my_strcpy(a, "Illegal seek"); break;
    case 30: my_strcpy(a, "Read-only file system"); break;
    }
    return a;
}


MyString::MyString()
{
    data = new char[1];
    sizee = 1;
    data[0] = '\0';
}
MyString::MyString(const MyString& s)
{
    unsigned i, j;
    for (i = 0; s.data[i] != '\0'; i++);
    data = new char[i + 1];
    sizee = i + 1;
    for (j = 0; j < sizee; j++)data[j] = s.data[j];
}
MyString::MyString(const char* cs)
{
    unsigned i, j;
    for (i = 0; cs[i] != '\0'; i++);
    sizee = i + 1;
    data = new char[sizee];
    for (j = 0; j < (sizee - 1); j++)data[j] = cs[j];
    data[i] = '\0';
}

MyString::MyString(const MyString& s, const size_t& pos, const size_t& n)
{
    unsigned i, j;
    data = new char[n + 1];
    sizee = n + 1;
    for (i = pos, j = 0; i < (pos + n); i++, j++)data[j] = s.data[i];
    data[n] = '\0';
}
MyString::MyString(const char* cs, const size_t& n)
{
    unsigned i;
    for (i = 0; cs[i] != '\0'; i++);
    sizee = n + 1;
    data = new char[sizee];
    for (i = 0; i < (sizee - 1) && i < n; i++)data[i] = cs[i];
    data[n] = '\0';
}
MyString::MyString(const size_t& n, const char& c)
{
    unsigned i;
    sizee = n + 1;
    data = new char[sizee];
    for (i = 0; i < n; i++)data[i] = c;
    data[n] = '\0';
}

MyString::~MyString() {
    if (this->data != NULL)
        delete[] this->data;
}


char* MyString::getText() {
    return data;
}

void MyString::setText(char* text) {
    delete[] this->data;

    this->sizee = my_strlen(text);
    this->data = new char[this->sizee];

    my_strncpy(this->data, text, this->sizee);
}

size_t MyString::getLength() const {
    return my_strlen(this->data);
}

void MyString::setLength(size_t sizee) {
    size_t old_length = this->getLength();
    char* old_data = this->data;

    this->sizee = sizee;
    this->data = new char[sizee];

    for (size_t i = 0; i < sizee; i++) {
        if (i < old_length) {
            this->data[i] = old_data[i];
        }
        else {
            this->data[i] = '\0';
        }
    }

    delete[] old_data;

    this->data[sizee] = '\0';
}

void MyString::add(const MyString& text) {
    size_t new_size = this->sizee + text.sizee;
    setLength(new_size);

    size_t length = getLength();
    for (size_t i = length; i < new_size; i++) {
        this->data[i] = text.data[i - length];
    }
}

char MyString::at(size_t pos) const {
    if (pos > getLength()) {
        return '\0';
    }
    return data[pos];
}
bool MyString::compare(const MyString& string) const {
    return my_strcmp(this->data, string.data) == 0;
}

char MyString::operator[](size_t pos) {
    return this->at(pos);
}

MyString operator+(const MyString& string1, const MyString& string2) {
    MyString string = MyString(string1);
    string.add(string2);

    return string;
}

bool operator==(const MyString& string1, const MyString& string2) {
    return string1.compare(string2);
}


bool MyString::empty() {
    if (sizee == 0) return 1;
    return 0;
}
void MyString::clear()
{
    if (this->data != NULL)
        delete[] this->data;
    sizee=0;
}
size_t MyString::capacity()
{
    return sizee;
}

void MyString::resize(size_t sizee, char c = '\0') {
    char* old_data = this->data;
    if (sizee > this->sizee) {
        this->data = new char[sizee];
        my_strcmp(this->data, old_data);
        for (size_t a = this->sizee; a < sizee; a++)
            this->data[a] = c;
    }
    else {
        this->data = new char[sizee];
        for (size_t a = 0; a < sizee; a++)
            this->data[a] = old_data[a];
    }
    this->sizee = sizee;
    delete[] old_data;
}


size_t MyString::max_size() {
    return INT_MAX;
}

size_t MyString::lenght() {
    return this->sizee;
}

size_t MyString::size() {
    return this->sizee;
}

char  MyString::back() const {
    if (this->sizee > 0) {
        return this->data[this->sizee - 1];
    }
}
char  MyString::front() const {
    if (this->sizee > 0) {
        return this->data[0];
    }
}


void MyString::append(MyString& string) {
    char* old_data = this->data;
    this->data = new char[sizee + string.size()+1];
    for (size_t a = 0; a < sizee; a++) this->data[a] = old_data[a];
    for (size_t a = 0; a < string.size(); a++) this->data[a + sizee] = old_data[a];
    this->sizee = sizee + string.size();
    data[sizee + string.size()]='\0';
    delete[] old_data;
}


void MyString::push_back(char q) {

    char* old_data = this->data;
    this->data = new char[sizee + 2];
    for (size_t a = 0; a < sizee; a++) this->data[a] = old_data[a];
    this->data[sizee] = q;
    this->data[sizee+1] = '\0';
    this->sizee = sizee + 1;
    delete[] old_data;
}

MyString& MyString::assign(const char* cs, const size_t& n)
{
    unsigned i;
    this->sizee = n + 1;
    this->data = new char[n + 1];
    for (i = 0; i < (this->sizee - 1); i++)
        this->data[i] = cs[i];
    this->data[this->sizee - 1] = '\0';
    return *this;
}

MyString& MyString::insert(const size_t& pos, const MyString& s)
{
    MyString str(data);
    unsigned i, j;
    sizee = s.sizee + str.sizee - 1;
    delete[] data;
    data = new char[sizee];
    for (i = 0; i < pos; i++)
        data[i] = str.data[i];
    for (i = pos, j = 0; j < (s.sizee - 1); i++, j++)
        data[i] = s.data[j];
    for (i = s.sizee + pos - 1, j = pos; i < sizee; i++, j++)
        data[i] = str.data[j];
    return *this;
}

size_t MyString::rfind(const char* s2)
{
    const size_t ln1 = my_strlen(data);
    const size_t ln2 = my_strlen(s2);

    if (ln1 < ln2)
        return size_t(-1);

    for (auto* it = data + ln1 - ln2, *end = data - 1; it != end; --it)
        if (my_strncmp(it, s2, ln2) == 0)
            return size_t(it - data);

    return size_t(-1);
}

int MyString::find(MyString textForFind)
{

    int j = 0;
    for (int i = 0; i < size(); i++) {
        if (data[i] == textForFind[j])
            j++;
        else if (j == textForFind.size())
            return j;
        else
            j = 0;
    }
    return -1;
}
MyString& MyString::erase(const size_t& pos, const size_t& n)
{
    unsigned i, j;
    MyString str(data);
    sizee = str.sizee - n;
    delete[] data;
    data = new char[sizee];
    for (i = 0; i < pos; i++)
        data[i] = str.data[i];
    for (i = pos, j = pos + n; j < str.sizee; i++, j++)data[i] = str.data[j];
    return *this;
}

MyString& MyString::replace(const size_t& pos, const size_t& n, const MyString& s)
{
    MyString str(data);
    unsigned i;
    str.erase(pos, n);
    str.insert(pos, s);
    sizee = str.sizee;
    delete[] data;
    data = new char[sizee];
    for (i = 0; i < sizee; i++)
        data[i] = str.data[i];
    return *this;
}

void MyString::swap(MyString& s)
{
    char* str = new char[sizee];
    size_t i = this->copy(str, sizee - 1, 0);
    str[i] = 0;
    *this = s;
    s = str;
    delete[] str;
}

size_t MyString::copy(char* cs, const size_t& n, const size_t& pos) const
{
    size_t i, j;
    for (j = pos, i = 0; i < n; i++, j++)
        cs[i] = data[j];
    return i;
}


void MyString::pop_back() {
    if(sizee>0){
    char* old_data = this->data;
    this->data = new char[sizee];
    for (size_t a = 0; a < sizee-1; a++) this->data[a] = old_data[a];
    data[sizee-1]='\0';
    this->sizee = sizee - 1;
    delete[] old_data;
    }
}


int MyString::find_first_of(MyString textForFind) {
    for (size_t a = 0; a < sizee; a++)
        for (size_t aa = 0; aa < textForFind.sizee; aa++)
            if (data[a] == textForFind[aa]) return a;
    return 0;
}

int MyString::find_last_of(MyString textForFind) {
    for (size_t a = sizee-1; a >=0; a--)
        for (size_t aa = 0; aa < textForFind.sizee; aa++)
            if (data[a] == textForFind[aa]) return a;
    return 0;
}


int MyString::find_first_not_of(MyString textForFind) {
    for (size_t a = 0; a < sizee; a++)
        for (size_t aa = 0; aa < textForFind.sizee; aa++)
            if (data[a] != textForFind[aa]) return a;
    return 0;
}

int MyString::find_last_not_of(MyString textForFind) {
    for (size_t a = sizee - 1; a >= 0; a--)
        for (size_t aa = 0; aa < textForFind.sizee; aa++)
            if (data[a] != textForFind[aa]) return a;
    return 0;
}


