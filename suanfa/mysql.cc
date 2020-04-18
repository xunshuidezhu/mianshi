#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDelete(vector<int>& nums, int x)
{
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = l;
    int tmp = 0;
    while (r < nums.size()) {
        if (nums[r] - nums[l] <= x) {
            r++;
        } else {
            tmp = max(tmp, r - l);
            l++;
            r = l;
        }
    }
    return nums.size() - tmp;
}

int main()
{
    int n;
    int x;
    while (cin >> n) {
        cin >> x;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << minDelete(nums, x) << endl;
    }
}