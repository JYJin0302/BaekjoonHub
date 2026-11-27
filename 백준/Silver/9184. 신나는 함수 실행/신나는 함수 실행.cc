#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int dp[101][101][101];

// 0-49 : -50 - -1
// 50 : 0
// 51 - 100 : 1 - 50

int w(int a, int b, int c) {

    if (dp[a][b][c] != INF) return dp[a][b][c];

    if (a <= 50 || b <= 50 || c <= 50) return dp[a][b][c] = 1;

    if (a > 70 || b > 70 || c > 70) return dp[a][b][c] = w(70, 70, 70);

    if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    int a, b, c;
    cin >> a >> b >> c;

    while (!(a == -1 && b == -1 && c == -1)) {

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(50 + a, 50 + b, 50 + c) << '\n';

        cin >> a >> b >> c;
    }

}