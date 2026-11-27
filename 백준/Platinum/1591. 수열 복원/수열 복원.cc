#include <bits/stdc++.h>
using namespace std;

vector<int> A[2010];
vector<int> adj[2010];
int inD[2010], idx[2010];

map<vector<int>, int> mp;
vector<int> ans;

void dfs(int v) {

    while (idx[v] < adj[v].size()) {
        int nv = adj[v][idx[v]++];
       // cout << "curr: " << v << " -> " << nv << '\n';
        dfs(nv);
        ans.push_back(A[nv].back());
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int cnt = 0;

    for (int i = 0; i < n - m + 1; i++) {
        vector<int> tmp(m);
        for (auto& j : tmp) cin >> j;

        vector<int> t1, t2;
        for (int j = 0; j < m; j++) {
            if (j < m - 1) t1.push_back(tmp[j]);
            if (j > 0) t2.push_back(tmp[j]);
        }

        if (!mp[t1]) {
            mp[t1] = ++cnt;
            A[cnt] = t1;
        }
        if (!mp[t2]) {
            mp[t2] = ++cnt;
            A[cnt] = t2;
        }
        inD[mp[t2]]++;
       // cout << mp[t1] << " -> " << mp[t2] << '\n';

        adj[mp[t1]].push_back(mp[t2]);
    }

    int ix = 1;
    for (int i = 1; i <= cnt; i++) {
        if (inD[i] < adj[i].size()) ix = i;
    }
    dfs(ix);
    //cout << ix;
    for (int i = m - 2; i >= 0; i--) {
        ans.push_back(A[ix][i]);
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans) cout << i << ' ';
}