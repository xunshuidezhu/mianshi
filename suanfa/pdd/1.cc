#include <bits/stdc++.h>

/**
 * 
 * 4
    100 200 300 400
 * 800
 * */
using namespace std;

int minMoney(vector<int>& v)
{
    int money = 0;
    sort(v.begin(), v.end(), greater<int>());
    int len = v.size();
    int times = len / 3;
    for (int i = 0; i < times; i++) {
        money += (v[i * 3] + v[i * 3 + 1]);
    }
    for (int i = times * 3; i < len; i++) {
        money += v[i];
    }
    return money;
}

int main()
{
    /* int n;
    while (cin >> n) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
    } */
    vector<int> v { 100, 200, 300, 400 };
    cout << minMoney(v) << endl;
}