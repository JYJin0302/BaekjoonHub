#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;

int o = 1;
vector<int> adj[200001];

int s[200001], e[200001], p[200001];
ll fw[400004], hval[200001];
bool isCut[200001];

void dfs(int v, int pv = 0) {
    s[v] = o++;
    for (auto i : adj[v]) if (i != pv) {
        dfs(i, v);
    }
    e[v] = o++;
}

void update(int ix, ll val) {
    while (ix < o) {
        fw[ix] ^= val;
        ix += ix & -ix;
    }
}

ll getVal(int ix) {
    ll res = 0;
    while (ix) {
        res ^= fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937 engine((unsigned int)time(NULL));
    uniform_int_distribution<ll> rnd(1ll, LLONG_MAX);


    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        p[i] = x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        hval[i] = rnd(engine);
    }

    dfs(1);

    while (q--) {

        int a, b, d;
        cin >> a >> b >> d;

        int l = s[a], r = s[b];
        ll val = getVal(r) ^ getVal(l);
        if (val == 0) {
            cout << "YES\n";
            if (d && !isCut[a]) {
                isCut[a] = 1;
                // cut a
                update(s[a], hval[a]);
                update(e[a], hval[a]);
            }
        }
        else {
            cout << "NO\n";
            if (d && !isCut[b]) {
                isCut[b] = 1;
                // cut b
                update(s[b], hval[b]);
                update(e[b], hval[b]);
            }
        }
    }
}