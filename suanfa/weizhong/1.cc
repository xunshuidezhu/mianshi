#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;
    while (cin >> n) {
        cin >> m;
        cin >> a;
        cin >> b;
        
        int num = n - m % n;
        if (a > b) {
            cout << num * b << endl;
        } else {
            cout << num * a << endl;
        }
    }
}