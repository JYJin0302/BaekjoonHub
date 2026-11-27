#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int A[5010][5010];
void solve() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int v = A[c][d] - A[a - 1][d] - A[c][b - 1] + A[a - 1][b - 1];
        c--, d--;
        a++, b++;
        int v2 = A[c][d] - A[a - 1][d] - A[c][b - 1] + A[a - 1][b - 1];
        cout << -v + 2 * v2 << '\n';

    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
