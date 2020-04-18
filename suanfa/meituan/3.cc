/**
 * 输入样例2
3
0.90 0.10 0.10
2 1 1
输出样例2
4.88

2
0.80 0.50
1 2

选择用一颗子弹射击：如果命中则再用一颗子弹进行射击，如果命中则再用一颗子弹进行射击（即3轮均使用了一颗子弹进行）：0.90 * 2 + 0.90 * 0.90 * 2+0.90 * 0.90 * 0.90 * 2= 4.878≈4.88  此种情况的期望得分最高，故为4.88
 * */

#include <bits/stdc++.h>

using namespace std;

double maxEx(vector<double>& p, vector<int>& a)
{
    int len = p.size();
    double dp[len + 1];
    memset(dp, 0, sizeof(double) * (len + 1));
    dp[1] = p[0] * a[0];
    for (int i = 2; i <= len; i++) {
        dp[i] = max(dp[i - 1] * p[0] * a[0] + p[0] * a[0], (double)p[i - 1] * a[i - 1]);
    }
    return dp[len];
}

int main()
{
    int n;
    while (cin >> n) {
        vector<double> p(n, 0);
        vector<int> a(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        double res = maxEx(p, a);
        cout << res << endl;
        printf("%.2f\n", res);
    }
}