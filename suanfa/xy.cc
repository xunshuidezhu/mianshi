#include <bits/stdc++.h>

using namespace std;

class D {
public:
    D() { cout << "a" << endl; }
};

int main()
{
    int x = 0, y = 0;

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if ((5 * x + y == 10) && (5 * x - y == 10)) {
                cout << x << "  " << y << endl;
            }
        }
    }
}