#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<bool>> check(101, vector<bool>(101));
    int x1, x2, y1, y2, ans = 0;
    for (int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int k = x1; k < x2; k++) for (int j = y1; j < y2; j++) {
            if (check[k][j]) continue;
            ans++;
            check[k][j] = 1;
        }
    }

    cout << ans;
}