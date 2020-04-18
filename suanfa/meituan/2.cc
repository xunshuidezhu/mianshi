#include <bits/stdc++.h>

using namespace std;

int flagNums(vector<int>& nums, int score)
{
    //留下的最多的烙印数
    int res = 0;
    //一圈消耗的魔法值
    int flag = 0;
    for (int i = 0; i < nums.size(); i++) {
        flag += nums[i];
    }
    //完整走几圈
    int steps = score / flag;
    res += steps * nums.size();
    //剩下的魔法值
    int magic = score % flag;
    cout << magic << endl;
    for (int i = 0; i < nums.size(); i++) {
        if (magic >= nums[i]) {
            magic -= nums[i];
            res++;
        }
    }
    return res;
}

int main()
{
    int n;
    int m;
    while (cin >> n) {
        cin >> m;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << flagNums(nums, m) << endl;
    }
}
/* 4 21
2 1 4 3 */