#include <bits/stdc++.h>

using namespace std;

// //最长回文子串
// int longestSubstr(string str)
// {
//     if (str.size() == 0) {
//         return 0;
//     }

//     if (str.size() == 1) {
//         return 1;
//     }

//     vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));

//     for (int i = 0; i < str.size(); i++) {
//         dp[i][i] = 1;
//     }
//     int maxNum = 0;
//     for (int j = 1; j < str.size(); j++) {
//         for (int i = 0; i < j; i++) {
//             if (str[i] == str[j]) {
//                 if (dp[i + 1][j - 1] == 1) {
//                     dp[i][j] = 1;
//                     maxNum = max(maxNum, j - i + 1);
//                 }
//             }
//         }
//     }
//     return maxNum;
// }

int numsOfOne(string str)
{
    map<char, int> m;
    int res = 0;
    for (auto s : str) {
        m[s]++;
    }
    for (auto i : m) {
        if (i.second % 2 == 1) {
            res++;
        }
    }
    return res;
}

int main()
{
    int nums;
    
    while (cin >> nums) {
        for (int i = 0; i < nums; i++) {
            string str;
            cin >> str;
            int num = numsOfOne(str);
            if (num <= 1) {
                cout << "" << endl;
            } else if (num % 2 == 1) {
                cout << "" << endl;
            } else if (num % 2 == 0) {
                cout << "" << endl;
            }
        }
    }
}