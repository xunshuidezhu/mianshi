#include <bits/stdc++.h>

using namespace std;

/**
 * 5 2
1 2 3 4 5
 * 
 * 6
 * 
 * **/

int numsOfHeXie(vector<int>& v, int m)
{
    int len = v.size();
    int subLen = len;
    int tmp = 0;
    int res = 0;
    while (subLen > 0) {
        for (int begin = 0; begin <= len - subLen; begin++) {
            for (int i = begin; i < begin + subLen; i++) {
                tmp += v[i];
            }
            if (tmp % m == 0) {
                res++;
            }
            tmp = 0;
        }
        subLen--;
    }
    return res;
}

int main()
{
    vector<int> v { 1, 2, 3, 4, 5 };
    cout << numsOfHeXie(v, 2);

    return 0;
}