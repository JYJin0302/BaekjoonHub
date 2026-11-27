#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int INF = 0x3f3f3f3f;

int conn[505][505];
vector<int> st[101010];

void solve() {

    int n, x;
    cin >> n >> x;

    memset(conn, INF, sizeof conn);
    for (int i = 1; i <= n; i++) {
        vector<int> A(5);
        for (auto& f : A) cin >> f;
        for (int j = 1; j < 5; j++) A[j] += j * x;

        st[i] = A;
        for (auto j : A) {
            for (auto k : A) {
                conn[j][k] = min(conn[j][k], 1);
            }
        }
    }
    for (int i = 1; i <= 5*x; i++) conn[i][i] = 0;

    for (int k = 1; k <= 5 * x; k++) {
        for (int i = 1; i <= 5*x; i++) {
            for (int j = 1; j <= 5*x; j++) {
                conn[i][j] = min(conn[i][j], conn[i][k] + conn[k][j]);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;

        int res = INF;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int v1 = st[s][i];
                int v2 = st[t][j];

                res = min(res, conn[v1][v2]);
            }
        }
        if (res == INF) cout << -1 << '\n';
        else cout << res + 1 << '\n';
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}