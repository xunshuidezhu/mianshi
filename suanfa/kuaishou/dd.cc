#include <bits/stdc++.h>

using namespace std;

int num = 2;

void ptr_move(int* ptr)
{
    ptr = &num;
}

int main()
{
    int* ptr = new int;
    *ptr = 11;
    ptr_move(ptr);
    cout << *ptr << endl;
}