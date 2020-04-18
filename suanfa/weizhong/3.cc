#include <bits/stdc++.h>

using namespace std;

struct Card {
    int a;
    int b;
};

int main()
{
    int nums;
    while (cin >> nums) {
        vector<Card> card(nums);
        for (int i = 0; i < nums; i++) {
            cin >> card[i].a;
            cin >> card[i].b;
        }
        int res = 0;
        int cardNum = 1;
        for (int i = 0; i < nums; i++) {
            if (card[i].b > 0) {
                res += card[i].a;
                cardNum += card[i].b - 1;
            }
        }
        vector<Card> tmp;
        for (auto i : card) {
            if (i.b == 0) {
                tmp.push_back(i);
            }
        }
        sort(tmp.begin(), tmp.end(), [](Card& left, Card& right) { return left.a > right.a; });
        for (int i = 0; i < cardNum && i < tmp.size(); i++) {
            res += tmp[i].a;
        }
        cout << res << endl;
    }
}

