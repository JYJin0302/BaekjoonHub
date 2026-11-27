#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, m;
vector<int> adj[100001];

vector<int> seg, lazy;

int s[100001], e[100001];
int o = 0;
void dfs(int v, int pv = -1) {
    s[v] = o++;
    for (auto i : adj[v]) if (i != pv) {
        dfs(i, v);
    }
    e[v] = o++;
}

void go_lazy(int l, int r, int n) {
    if (lazy[n] == 0) return;
    if (lazy[n] == 1) {
        // turn on
        seg[n] = r - l + 1;
    }
    else {
        // turn off
        seg[n] = 0;    
    }
    if (l != r) {
        lazy[n * 2] = lazy[n];
        lazy[n * 2 + 1] = lazy[n];
    }
    lazy[n] = 0;
}

void update(int l, int r, int n, int ul, int ur, int t) {
    go_lazy(l, r, n);
    if (ul > ur) return;
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
        lazy[n] = t;
        go_lazy(l, r, n);
        return;
    }

    int m = (l + r) >> 1;
    update(l, m, n * 2, ul, ur, t);
    update(m + 1, r, n * 2 + 1, ul, ur, t);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int ssum(int l, int r, int n, int sl, int sr) {
    go_lazy(l, r, n);
    if (sl > sr) return 0;
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;
    return ssum(l, m, n * 2, sl, sr) + ssum(m + 1, r, n * 2 + 1, sl, sr);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int sz = 1;
    while (sz < 2*n) sz *= 2;
    seg = vector<int>(sz * 2);
    lazy = vector<int>(sz * 2);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x) {
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }

    dfs(1);
    
    //for (int i = 1; i <= n; i++) cout << s[i] << ' ' << e[i] << '\n';

    update(0, sz - 1, 1, s[1], e[1], 1);
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;

        if (a == 3) {
            cout << ssum(0, sz - 1, 1, s[b]+1, e[b]-1) / 2 << '\n';
        }
        else {
            update(0, sz - 1, 1, s[b]+1, e[b]-1, a);
        }

        /*
        cout << "CURR:\n";
        for (auto i : seg) cout << i << ' ';
        cout << '\n';
        for (auto i : lazy) cout << i << ' ';
        cout << '\n';
        */
    }


}