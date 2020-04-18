#include <bits/stdc++.h>

using namespace std;

void game(vector<vector<int>>& v, int m, int row, int col, int& length)
{
    int xLeft = row - length;
    int flag = 0;
    if (xLeft < 0) {
        xLeft = 0;
    }
    int xRight = row + length;
    if (xRight >= m) {
        xRight = m - 1;
    }
    int yUp = col - length;
    if (yUp < 0) {
        yUp = 0;
    }
    int yDown = col + length;
    if (yDown >= m) {
        yDown = m - 1;
    }
    for (int x = xLeft; x <= xRight; x++) {
        for (int y = yUp; y <= yDown; y++) {
            if (abs(x - row) + abs(y - col) <= length && v[x][y] != 0) {
                length += v[x][y];
                v[x][y] = 0;
                flag = 1;
            }
        }
    }
    if (flag) {
        game(v, m, row, col, length);
    } else {
        return;
    }
}

int main()
{
    int t = 0;
    while (cin >> t) {
        for (int i = 0; i < t; i++) {
            int m, p;
            cin >> m;
            cin >> p;
            vector<vector<int>> v(m, vector<int>(m, 0));
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < m; y++) {
                    cin >> v[x][y];
                }
            }
            int row, col;
            cin >> row;
            cin >> col;
            game(v, m, row, col, p);
            cout << p << endl;
        }
    }
    return 0;
}