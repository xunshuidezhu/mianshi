#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    while (cin >> x) {
        x = abs(x);
        int dp[x + 1];
        memset(dp, 0, sizeof(int) * (x + 1));
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= x; i++) {
            if (i % 50 == 0) {
                dp[i] = 0;
                continue;
            } else if (i % 50 == 1) {
                dp[i] = 1;
                continue;
            }
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        cout << dp[x] << endl;
    }
}