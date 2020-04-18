#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> v_num;
        vector<char> v_char;
        for (auto& i : s) {
            if (i >= '0' && i <= '9') {
                v_num.push_back(i);
            } else if (i >= 'a' && i <= 'z') {
                v_char.push_back(i);
            }
        }
        string res;
        if (v_num.size() == 0 || v_char.size() == 0) {
            return res;
        }
        if (abs(v_num.size() - v_char.size()) > 1) {
            return res;
        }
        
        if (v_num.size() > v_char.size()) {
            int len = v_char.size();
            for (int i = 0; i < len; i++) {
                res += v_num[i];
                res += v_char[i];
            }
            res += v_num[len];
        } else if (v_num.size() < v_char.size()) {
            int len = v_num.size();
            for (int i = 0; i < len; i++) {
                res += v_char[i];
                res += v_num[i];
            }
            res += v_char[len];
        } else {
            int len = v_num.size();
            for (int i = 0; i < len; i++) {
                res += v_char[i];
                res += v_num[i];
            } 
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.reformat("1a20x");
}