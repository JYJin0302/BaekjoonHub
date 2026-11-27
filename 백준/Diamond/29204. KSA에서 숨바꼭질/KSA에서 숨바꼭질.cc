#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

vector<int> adj[2020];

int n;
int dp[4020][2020];
int sz[4020];

pair<int, int> sbt[4040];
map<pair<int, int>, int> ptoi;

void dfs(int v, int pv = -1) {

    int idx = ptoi[mp(v, pv)];
    if (dp[idx][0] != -1) return;
    

    sz[idx] = 1;
    vector<vector<int>> tmp(n + 1);

    for (auto i : adj[v]) if (i != pv) {
        dfs(i, v);
        int ti = ptoi[mp(i, v)];
        sz[idx] = max(sz[idx], sz[ti] + 1);

        for (int j = 0; j < sz[ti]; j++) {
            tmp[j + 1].push_back(dp[ti][j]);
        }
    }

    for (int i = 1; i < sz[idx]; i++) {
        sort(tmp[i].rbegin(), tmp[i].rend());

        int res = 0;
        for (int j = 0; j < tmp[i].size(); j++) {
            res = max(res, tmp[i][j] + j);
        }
        dp[idx][i] = res;
        if (tmp[i].empty()) dp[v][i] = 0;
    }
    dp[idx][0] = 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n * 2; i++) dp[i][0] = -1;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        sbt[i*2] = mp(a, b);
        sbt[i * 2 + 1] = mp(b, a);
        ptoi[mp(a, b)] = i * 2;
        ptoi[mp(b, a)] = i * 2 + 1;
    }


    int ans = n+10;
    for (int i = 1; i <= n; i++) {
        int tans = 0;
        vector<vector<int>> tmp(n);

        vector<int> res(n);
        int sz1 = 1;
        for (auto f : adj[i]) {
            dfs(f, i);
            int ix = ptoi[mp(f, i)];

            for (int k = 0; k < sz[ix]; k++) {
                tmp[k + 1].push_back(dp[ix][k]);
            }
            sz1 = max(sz1, sz[ix] + 1);
        }

        for (int f = 0; f < sz1; f++) {
            sort(tmp[f].rbegin(), tmp[f].rend());

            for (int k = 0; k < tmp[f].size(); k++) {
                res[f] = max(res[f], tmp[f][k] + k);
            }
        }

        tans = *max_element(res.begin(), res.end());
        ans = min(ans, tans + 1);

        //cout << i << ' ' << tans << '\n';
    }
    cout << ans;

}