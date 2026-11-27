#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<ll, ll>> adj[404040], rev[404040];

int val[404040];

void solve(){

    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, ll>> edg;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        rev[b].push_back(mp(a, c));
        edg.push_back(mp(mp(a, b), c));
    }

    vector<ll> dist(n + 1, -1);
    priority_queue<pair<ll, ll>> pq;
    pq.push(mp(0, n));
    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (dist[b] != -1) continue;
        dist[b] = -a;
        
        for (auto [u, v] : rev[b]) {
            if (dist[u] == -1) {
                pq.push(mp(a - v, u));
            }
        }
    }

    if (dist[1] == -1) {
        cout << -1 << '\n';
        return;
    }


    int curVal = -1;
    queue<int> q;
    vector<int> lst;
    for (int i = 1; i <= n; i++) {
        val[i] = -10;
        if (dist[i] == -1) {
            val[i] = -1;
            q.push(i);
        }
    }

    vector<int> cnt(n + 1), inp(n+1);
    for (int i = 1; i < n; i++){
        for (auto [a, b] : adj[i]) {
            if (dist[a] != -1 && dist[i] == dist[a] + b) inp[i]++;
        }
    }
    while (1) {
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto [u, v] : rev[a]) {
                if (val[u] != -10 || u == n) continue;
                lst.push_back(u);
                
                if (dist[a] != -1 && dist[u] == dist[a] + v) {
                    cnt[u]++;
                    if (cnt[u] == inp[u]) {
                        q.push(u);
                        val[u] = curVal;
                    }
                }                
            }
        }


        if (lst.empty()) break;
        sort(all(lst));
        int pre = -1;
        for (auto f : lst) {
            if (val[f] == curVal || f == pre) continue;
            pre = f;
            q.push(f);
            val[f] = curVal + 1;
        }
        lst.clear();
        curVal++;
    }

    if (val[1] == -10) val[1] = n;
    cout << val[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}