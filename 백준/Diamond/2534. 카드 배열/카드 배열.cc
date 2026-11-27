#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll mod = 1e9 + 7;
vector<int> adj[303030];
vector<int> rev[303030];

ll pw[303030];
int topo[303030];

void solve() {
    ll n, k, p;
    cin >> n >> k >> p;

    pw[0] = 1;
    for (int i = 1; i < n; i++) pw[i] = pw[i - 1] * n % mod;

    while (p--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    ll minV = 0, maxV = 0;

    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        topo[i] = rev[i].size();
        if (topo[i] == 0) pq.push(-i);
    }

    int val = k-1;
    while (!pq.empty()) {
        int x = -pq.top(); pq.pop();
        minV += pw[x] * val % mod;
        minV %= mod;
        val--;
        for (auto f : adj[x]) {
            topo[f]--;
            if (topo[f] == 0) pq.push(-f);
        }
    }
    for (int i = 0; i < k; i++) {
        topo[i] = adj[i].size();
        if (topo[i] == 0) pq.push(-i);
    }
    val = n-k;
    while (!pq.empty()) {
        int x = -pq.top(); pq.pop();
        maxV += pw[x] * val % mod;
        maxV %= mod;
        val++;
        for (auto f : rev[x]) {
            topo[f]--;
            if (topo[f] == 0) pq.push(-f);
        }
    }

    cout << (maxV - minV + mod) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}