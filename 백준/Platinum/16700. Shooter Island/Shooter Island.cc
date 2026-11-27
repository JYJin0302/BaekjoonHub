#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second

int dp[51][101010];
int root[5101010];
int find(int i, int n) {
    if (dp[i][n] == n) return n;
    return dp[i][n] = find(i, dp[i][n]);
}

int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void solve() {

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 100000 + 10; j++) {
            dp[i][j] = j;
            root[i * 100000 + j] = i * 100000 + j;
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        if (t == 0) {
            // connect
            if (a > c) swap(a, c);
            if (b > d) swap(b, d);

            for (int f = a; f <= c; f++) {
                // b - d 
                int ti = b;
                while (ti <= d) {
                    int ni = find(f, ti);
                    if (ni <= d) {
                        dp[f][ni] = ni + 1;
                        ti = ni;

                        int curr = find(f * 100000 + ni);
                        // connect 4 sides
                        if (f) {
                            // try f-1, ni
                            if (dp[f - 1][ni] != ni) {
                                int tmp = find((f - 1) * 100000 + ni);
                                if (tmp != curr) root[tmp] = curr;
                            }
                        }

                        if (ni) {
                            // try f, ni-1
                            if (dp[f][ni-1] != ni-1) {
                                int tmp = find(f * 100000 + ni - 1);
                                if (tmp != curr) root[tmp] = curr;
                            }
                        }

                        if (f + 1 < 50) {
                            // try f-1, ni
                            if (dp[f + 1][ni] != ni) {
                                int tmp = find((f + 1) * 100000 + ni);
                                if (tmp != curr) root[tmp] = curr;
                            }
                        }

                        if (ni + 1 < 100000) {
                            // try f, ni-1
                            if (dp[f][ni + 1] != ni + 1) {
                                int tmp = find(f * 100000 + ni + 1);
                                if (tmp != curr) root[tmp] = curr;
                            }
                        }

                    }
                    else break;
                }
            }

        }
        else {

            int p1 = a * 100000 + b;
            int p2 = c * 100000 + d;
            cout << bool(find(p1) == find(p2) && dp[c][d] != d) << '\n';

        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    solve();
    return 0;
}
