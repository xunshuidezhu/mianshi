#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int flag = 1;
        bool first = false;
        string tmp;
        for (auto i : str) {
            if ((!first && i == '-') || (i >= '0' && i <= '9')) {
                first = true;
                if (i == '-') {
                    flag = -1;
                }
                if (i >= '0' && i <= '9') {
                    tmp += i;
                }
            } else if (!first && i == ' ') {
                continue;
            } else {
                break;
            }
        }
        long long res = 0;

        for (int i = tmp.size() - 1; i >= 0; i--) {
            int num = tmp[tmp.size() - i - 1] - '0';
            res += num * pow(10, i);
        }
        res = res * flag;
        if (res >= INT_MAX || res <= INT_MIN) {
            res = INT_MAX;
        }
        return (int)res;
    }
};

int main()
{
    Solution s;
    int res = s.myAtoi("43");
    cout << res << endl;
}