#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

const int mod = 1e9 + 7;
ll C[33][33];


map<vector<pair<int, int>>, int> idx;

vector<pair<int, int>> adj[6060];

ll dp[55][6060];
ll getDp(int k, int ix) {
    if (dp[k][ix] != -1) return dp[k][ix];
    if (k == 0) {
        if (ix == 1) return dp[k][ix] = 1;
        return dp[k][ix] = 0;
    }
    ll res = 0;
    for (auto [a, b] : adj[ix]) {
        res += getDp(k - 1, a) * b % mod;
        res %= mod;
    }
    return dp[k][ix] = res;

}

void solve() {

    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= 30; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }

    int n, k, t;
    cin >> n >> k >> t;

    vector<pair<int, int>> tmp;
    tmp.push_back(mp(1, n));

    queue<vector<pair<int, int>>> q;
    q.push(tmp);

    int cnt = 0, c2 = 0;
    idx[tmp] = 1;
    int ord = 1;
    while (!q.empty()) {
        vector<pair<int, int>> cur = q.front();
        q.pop();
        cnt++;

        int cdx = idx[cur];
        int sz = cur.size();
        vector<int> tcnt(n + 1);
        for (auto [a, b] : cur) tcnt[a] = b;

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (tcnt[i] == 0 || tcnt[j] == 0) continue;

                vector<int> ncnt = tcnt;
                if (i == j) {
                    // spllit
                    int len = i;
                    if (len > 1) {

                        for (int f = 1; f * 2 <= len; f++) {
                            ncnt = tcnt;
                            ncnt[i]--;
                            ncnt[f]++;
                            ncnt[i - f]++;

                            ll mult = 0;
                            if (f * 2 == len) mult = len / 2;
                            else mult = len;
                            mult = mult * tcnt[i] % mod;

                            vector<pair<int, int>> t2;
                            for (int w = 0; w <= n; w++) {
                                if (ncnt[w]) t2.push_back(mp(w, ncnt[w]));
                            }

                            if (!idx[t2]) {
                                idx[t2] = ++ord;
                                q.push(t2);
                            }

                            adj[cdx].push_back(mp(idx[t2], mult));
                        }
                    }

                    // merge
                    if (tcnt[i] >= 2) {
                        ncnt = tcnt;
                        ncnt[i] -= 2;
                        ncnt[i + i]++;

                        ll mult = C[tcnt[i]][2] * i * i % mod;
                        vector<pair<int, int>> t2;
                        for (int w = 0; w <= n; w++) {
                            if (ncnt[w]) t2.push_back(mp(w, ncnt[w]));
                        }

                        if (!idx[t2]) {
                            idx[t2] = ++ord;
                            q.push(t2);
                        }

                        adj[cdx].push_back(mp(idx[t2], mult));
                    }

                }
                else {
                    // merge

                    ll mult = 1ll * tcnt[i] * tcnt[j] % mod * i % mod * j % mod;
                    ncnt[i]--;
                    ncnt[j]--;
                    ncnt[i + j]++;

                    vector<pair<int, int>> t2;
                    for (int w = 0; w <= n; w++) {
                        if (ncnt[w]) t2.push_back(mp(w, ncnt[w]));
                    }

                    if (!idx[t2]) {
                        idx[t2] = ++ord;
                        q.push(t2);
                    }

                    adj[cdx].push_back(mp(idx[t2], mult));

                }
            }
        }
    }


    memset(dp, -1, sizeof dp);

    while (t--) {

        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            A[i]--;
        }

        vector<int> cc(n + 1);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int ti = i;
            int cnt = 0;
            while (!vis[ti]) {
                cnt++;
                vis[ti] = 1;
                ti = A[ti];
            }
            cc[cnt]++;
        }

        vector<pair<int, int>> s;
        for (int i = 1; i <= n; i++) if (cc[i]) s.push_back(mp(i, cc[i]));

        int ix = idx[s];
        cout << getDp(k, ix) << '\n';

    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}