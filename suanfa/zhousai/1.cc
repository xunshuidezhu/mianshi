#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words)
    {
        vector<string> res;
        sort(words.begin(), words.end(), [](string l, string r) { return l.size() < r.size(); });
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[j].find(words[i]) != words[j].npos) {
                    if (find(res.begin(), res.end(), words[i]) == res.end()) {
                        res.push_back(words[i]);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<string> v = { "asd", "a", "dddddd" };
    Solution s;
    s.stringMatching(v);
    for (auto i : v) {
        cout << i << endl;
    }
}
