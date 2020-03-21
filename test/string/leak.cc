#include <bits/stdc++.h>

using namespace std;

int num = 0;

void* operator new(size_t size, const char* file, long line)
{
    num++;
    void* buf = malloc(size);
    return buf;
}

int main()
{
    char* msg = new char;
    cout << num << endl;
    map<int, int> m;
    m[0] = 1;
    map<int, int> n;
    n = m;
    cout << n[0] << endl;   

    return 0;
}