#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>

#define MAX 999999

using namespace std;

int main()
{
    int n, m, k;
    while (cin >> n) {
        cin >> m;
        cin >> k;
        vector<pair<int, int>> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i].first >> v[i].second;
        }
        int dx = 0;
        int dy = 0;
        double minDistance = (double)MAX;
        double maxDxDy;
        double distance;
        double res;
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= m; y++) {
                maxDxDy = 0;
                distance = 0;

                for (int i = 0; i < k; i++) {
                    int pointx = v[i].first;
                    int pointy = v[i].second;
                    dx = abs(pow(pointx, 2) - pow(x, 2));
                    dy = abs(pow(pointy, 2) - pow(y, 2));
                    if (sqrt(dx + dy) > maxDxDy) {
                        maxDxDy = sqrt(dx + dy);
                    }
                    distance += sqrt(dx + dy);
                }
                if (distance < minDistance) {
                    minDistance = distance;
                    res = maxDxDy;
                }
            }
        }
        printf("%.4f", res);
    }
}