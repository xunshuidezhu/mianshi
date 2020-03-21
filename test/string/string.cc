#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class MyString {
public:
    MyString(const char* str = NULL); //普通的构造函数
    MyString(const MyString& other); //拷贝构造函数
    ~MyString();
    MyString& operator=(const MyString& other);

private:
    char* m_data; //用于保存字符串
};

MyString::MyString(const char* str)
{
    if (str == NULL) {
        m_data = new char[1];
        *m_data = '\0';
    } else {
        int len = strlen(str);
        m_data = new char[len + 1];
        strcpy(m_data, str);
    }
}

MyString::~MyString()
{
    if (m_data != NULL) {
        delete[] m_data;
        m_data = NULL;
    }
}

MyString::MyString(const MyString& other)
{
    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, other.m_data);
}

MyString& MyString::operator=(const MyString& other)
{
    if (*this == const_cast<MyString&>(other)) {
        return *this;
    }
    delete[] m_data;
    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, other.m_data);
    return *this;
}