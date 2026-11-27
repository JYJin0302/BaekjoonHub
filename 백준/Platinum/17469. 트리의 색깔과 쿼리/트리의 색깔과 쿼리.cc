#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Q {
    int t, a;
};

int p[100001];
int color[100001];
int root[100001];
int sz[100001];
int find(int n) {
    if (root[n] == n)return n;
    return root[n] = find(root[n]);
}

set<int> tmp[100001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        root[i] = i;
        sz[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
        tmp[i].insert(color[i]);
    }

    vector<Q> query(q+n-1);
    for (auto& i : query) {
        cin >> i.t >> i.a;
    }
    reverse(query.begin(), query.end());

    vector<int> ans;

    for (auto i : query) {

        if (i.t == 1) {
            // merge i.a, p[i.a]
            int u = i.a, v = p[i.a];
            u = find(u), v = find(v);

            if (sz[u] > sz[v]) swap(u, v);
            // u -> v

            for (auto j : tmp[u]) {
                tmp[v].insert(j);
            }
            sz[v] = tmp[v].size();

            root[u] = v;
        }
        else {
            int u = find(i.a);
            ans.push_back(tmp[u].size());
        }
    }


    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << '\n';
}