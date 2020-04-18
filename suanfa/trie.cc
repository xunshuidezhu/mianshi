#include <bits/stdc++.h>

using namespace std;

class Tire {
public:
    Tire* children[26];
    int size;
    bool isend = false;
    Tire()
    {
        size = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = "";
        Tire* root = new Tire();
        for (int i = 0; i < strs.size(); i++) {
            Tire* p = root;
            if (strs[i].empty())
                return ans;
            for (int j = 0; j < strs[i].length(); j++) {
                if (p->children[strs[i][j] - 'a'] == NULL) {
                    p->children[strs[i][j] - 'a'] = new Tire();
                    p->size++;
                }
                p = p->children[strs[i][j] - 'a'];
            }
            p->isend = true;
        }
        Tire* q = root;
        int k = 0;
        while (q->size == 1 && q->isend == false) {
            for (k = 0; k < 26; k++) {
                if (q->children[k]) {
                    char temp = k + 'a';
                    ans += temp;
                    break;
                }
            }
            q = q->children[k];
        }
        return ans;
    }
};


int main()
{
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(1);
    pq1.push(0);

    priority_queue<int, vector<int>, less<int>> pq2;
    pq2.push(3);
    pq2.push(10);
    pq2.push(-1);
    cout << pq1.top() << endl;
    cout << pq2.top() << endl;
}