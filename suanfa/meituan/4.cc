#include <bits/stdc++.h>

using namespace std;

bool isABA(string& s, int k)
{
	int len = s.size();
    for (int i = k; i <= len / 2; i++) {
        string subLeft = s.substr(0, i);
        string subRight = s.substr(len - i, i);
        if (subLeft == subRight) {
            return true;
        }
    }
    return false;
}

int f_sum(string& s, int k)
{
    int res = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
            string sub = s.substr(i, j - i + 1);
            if (isABA(sub, k)) {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    string s;
    while (cin >> s) {
        int k;
        cin >> k;
        cout << f_sum(s, k) << endl;
    }
}

/* abcabcabc
2 */