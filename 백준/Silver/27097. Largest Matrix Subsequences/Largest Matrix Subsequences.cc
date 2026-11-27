#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int A[151][151], dp[151][151], dpR[151][151], dpC[151][151];;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }


    int ans = 1;
    vector<tuple<int, int, int, int>> res;

    for (int i = 0; i < n; i++) {
        dpR[i][0] = 1;
        for (int j = 1; j < m; j++) {
            if (A[i][j - 1] < A[i][j]) dpR[i][j] = dpR[i][j - 1] + 1;
            else dpR[i][j] = 1;

            if (ans == dpR[i][j]) {
                res.push_back({ i + 1, j - ans + 2, 1, ans });
            }
            else if (ans < dpR[i][j]) {
                ans = dpR[i][j];
                res.clear();
                res.push_back({ i + 1, j - ans + 2, 1, ans });
            }
        }
    }
    for (int j = 0; j < m; j++) {
        dpC[0][j] = 1;
        for (int i = 1; i < n; i++) {
            if (A[i - 1][j] < A[i][j]) dpC[i][j] = dpC[i - 1][j] + 1;
            else dpC[i][j] = 1;

            if (ans == dpC[i][j]) {
                res.push_back({ i - ans + 2, j + 1, ans, 1 });
            }
            else if (ans < dpC[i][j]) {
                ans = dpC[i][j];
                res.clear();
                res.push_back({ i - ans + 2, j + 1, ans, 1 });
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (A[i][j] > A[i - 1][j] && A[i][j] > A[i][j - 1] && \
                A[i - 1][j] > A[i - 1][j - 1] && A[i][j - 1] > A[i - 1][j - 1]) dp[i][j] = 1;
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

        }
    }

    for (int u = 0; u < n; u++) {
        for (int d = u+1; d < n; d++) {

            int ix = m-1, pv = ix;
            int len = d - u + 1;
            while (ix >= 0) {

                if (dpC[d][ix] < len) {
                    ix--;
                    pv = ix;
                    continue;
                }

                int val = dp[d][pv] - dp[d][ix] - dp[u][pv] + dp[u][ix];
                if (val == (len - 1) * (pv - ix)) {
                    int nv = len * (pv - ix + 1);
                    if (ans == nv) {
                        res.push_back({ u + 1, ix + 1, len, pv - ix + 1 });
                    }
                    else if (ans < nv) {
                        ans = nv;
                        res.clear();
                        res.push_back({ u + 1, ix + 1, len, pv - ix + 1 });
                    }
                    ix--;
                }
                else {
                    pv = ix;
                    ix--;
                }
            }
        }
    }




    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (auto i : res) {
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << ' ' << get<3>(i) << '\n';
    }

}