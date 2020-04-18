#include <iostream>

using namespace std;

bool game(int* stones, int size)
{
    int maxStone = stones[0];
    for (int i = 1; i < size; i++) {
        if (stones[i] > maxStone) {
            maxStone = stones[i];
        }
    }
    cout << maxStone << endl;
    if (maxStone % 2 == 1) {
        return false;
    }
    return true;
}

int main()
{
    int t = 0;
    int n = 0;
    while (cin >> t) {
        for (int i = 0; i < t; i++) {
            cin >> n;
            int stones[n];
            for (int j = 0; j < n; j++) {
                cin >> stones[j];
            }
            bool res = game(stones, n);
            if (res == true) {
                cout << "man" << endl;
            } else {
                cout << "woman" << endl;
            }
        }
    }
    return 0;
}
/* 2
1 
0
2
2 2
 */