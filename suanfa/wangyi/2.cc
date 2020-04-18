#include <bits/stdc++.h>

using namespace std;



int main()
{
    int t;
    while (cin >> t) {
        for (int i = 0; i < t; i++) {
            int n, m;
            cin >> n;
            cin >> m;
            vector<set<int>> v;
            for (int k = 0; k < n; k++) {
                v.push_back({k + 1});
            }
            for (int j = 0; j < m; j++) {
                int op;
                cin >> op;
                if (op == 1) {
                    int x, y;
                    cin >> x;
                    cin >> y;
                    int xPos, yPos;
                    for (int p = 0; p < v.size(); p++) {
                        if (v[p].count(x)) {
                            xPos = p;
                        }
                        if (v[p].count(y)) {
                            yPos = p;
                        }
                    }
                    if (xPos == yPos) {
                        continue;
                    } else {
                        v[yPos].erase(y);
                        v[xPos].insert(y);
                    }
                } else if (op == 2) {
                    int x;
                    cin >> x;
                    for (int p = 0; p < v.size(); p++) {
                        if (v[p].count(x)) {
                            if (v[p].size() == 1) {
                                continue;
                            } else {
                                v[p].erase(x);
                                v.push_back({x});
                            }
                        }
                    }
                } else if (op == 3) {
                    int x;
                    cin >> x;
                    for (int p = 0; p < v.size(); p++) {
                        if (v[p].count(x)) {
                            cout << v[p].size() << endl;
                        }
                    }
                }
            }
        }
    }
}
