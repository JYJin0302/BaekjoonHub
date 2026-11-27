#include <bits/stdc++.h>
using namespace std;

int A[101][101];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < 10 && a + j <= 100; j++) {
            for (int k = 0; k < 10 && b + k <= 100; k++) {
                A[a + j][b + k] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) ans += A[i][j];
    }
    cout << ans;

}