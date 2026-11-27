#include <bits/stdc++.h>
using namespace std;

int clz(int x) {
    if (x == 0) return 32;
    int res = 0, curr = 31;
    while (1) {
        
        if (x & (1 << curr)) return res;
        res++;
        curr--;
    }
}

int ctz(int x) {
    x = x & -x;
    return log2(x);
}

bool dp[1010][1 << 14];
int from[1010][1 << 14];
char ch[1010][1 << 14];
void solve() {

    int n;
    cin >> n;

    vector<int> A(n), sA(n);
    for (auto& i : A) cin >> i;
    sA[0] = A[0];
    for (int i = 1; i < n; i++) sA[i] = sA[i - 1] + A[i];

    int tot = sA[n - 1];

    if (tot != (1 << ctz(tot))) {
        cout << "no\n";
        return;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= tot; j++) {
            dp[i][j] = 0;
            from[i][j] = 0;
            ch[i][j] = '?';
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= tot; j++) {
            if (!dp[i][j]) continue;
            // add A[i]


            // left
            int al = ctz(j);

            if (j == 0 || A[i] <= (1 << al)) {
                dp[i + 1][j + A[i]] = 1;
                from[i + 1][j + A[i]] = j;
                ch[i + 1][j + A[i]] = 'l';
            }

            if (j == 0) continue;
            int rm = sA[i] - A[i] - j;

            if (j == (1 << ctz(j)) && A[i] > j) {
                dp[i + 1][A[i]] = 1;
                from[i + 1][A[i]] = j;
                ch[i + 1][A[i]] = 'l';
            }

            //assert(rm >= 0);

            int br = 31 - clz(rm);
            int bl = ctz(rm);
            // right

            if (rm == 0 || A[i] <= (1 << bl)) {
                rm += A[i];

                int tr = 31 - clz(rm);

                if (tr >= 31 - clz(j)) {
                    dp[i + 1][j + (1 << tr)] = 1;
                    from[i + 1][j + (1 << tr)] = j;
                    ch[i + 1][j + (1 << tr)] = 'r';
                }
                else {
                    dp[i + 1][j] = 1;
                    from[i + 1][j] = j;
                    ch[i + 1][j] = 'r';
                }
            }
        }
    }

    if (!dp[n][tot]) cout << "no\n";
    else {
        int ix = n, ij = tot;
        string res;
        while (ix) {
            res += ch[ix][ij];
            ij = from[ix][ij];
            ix--;
        }
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}