#include <iostream>

using namespace std;

struct A {
    int a;
    char c;
    long long d;
};

struct B {
    A d;
    int a;
};

int main()
{
    cout << sizeof(B) << endl;
    int a = 1;
    char c = static_cast<char>(a);
}