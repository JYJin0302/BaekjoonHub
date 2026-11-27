#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[1001010];
ll A[1001010];

int maxD = 0;
int dep[1001010];
int mD[1001010];
bool vis[1001010];

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void dfs(int v) {
    vector<int> res;
    vis[v] = 1;
    for (auto f : adj[v]) if (!vis[f] && A[f] == 1) {
        dfs(f);
        res.push_back(dep[f]);
        sort(all(res));
        reverse(all(res));
        if (res.size() > 2) res.pop_back();
    }
    while (res.size() < 2) res.push_back(0);
    sort(all(res));
    reverse(all(res));
    maxD = max(maxD, res[0] + res[1] + 1);
    dep[v] = res[0] + 1;
   // cout << "Dep: " << v << " | " << dep[v] << '\n';
}

void dfs2(int v, int pv = -1, int pval = 0) {
    vector<pair<int, int>> res;
    res.push_back(mp(pval, pv));
    for (auto f : adj[v]) if (f != pv && A[f] == 1) {
        res.push_back(mp(dep[f], f));
    }
    sort(all(res));
    reverse(all(res));
    mD[v] = res[0].x + 1;
   // cout << " MAX D : " << v << " | " << mD[v] << '\n';
    for (auto f : adj[v]) if (f != pv && A[f] == 1) {
        for (auto [a, b] : res) {
            if (b == f) continue;
            dfs2(f, v, a+1);
            break;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll mn = A[1];
    for (int i = 1; i <= n; i++) mn = min(mn, A[i]);

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && A[i] == 1) {
            //cout << "Go dfs: " << i << '\n';
            dfs(i);
            dfs2(i);
        }
    }

    ll p, q;
    if (maxD) {
        p = 1, q = maxD;
    }
    else p = mn, q = 1;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) continue;

        vector<int> tmp;
        for (auto f : adj[i]) if (A[f] == 1) {
            tmp.push_back(mD[f]);
        }
        while (tmp.size() < 2) tmp.push_back(0);
        sort(all(tmp));
        reverse(all(tmp));

        ll tp = A[i], tq = tmp[0] + tmp[1] + 1;

        ll g = gcd(tp, tq);
        tp /= g, tq /= g;

        if (p * tq > q * tp) {
            p = tp, q = tq;
        }
    }
    cout << p << '/' << q << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}