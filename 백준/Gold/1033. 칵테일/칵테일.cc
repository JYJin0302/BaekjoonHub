#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> A;
vector<vector<int>> adj;

void dfs(int v, int pv, int mul) {

    A[v] *= mul;
    for (int i : adj[v]) {
        if (i != pv) {
            dfs(i, v, mul);
        }
    }
}

ll gcd(ll a, ll b) {

    if (a < b) swap(a, b);

    if (b == 0) return a;

    return gcd(b, a % b);
}


int main() {

    int n;
    cin >> n;

    A = vector<ll>(n, 1);

    adj = vector<vector<int>>(n);

    vector<tuple<int, int, int, int>> mix;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        adj[a].push_back(b);
        adj[b].push_back(a);

        mix.push_back({ a, b, c, d });
    }

    for (auto i : mix) {
        int a, b, c, d;
        tie(a, b, c, d) = i;

        dfs(a, b, c);
        dfs(b, a, d);
    }

    ll t = A[0];
    for (int i = 1; i < n; i++) {
        t = gcd(t, A[i]);
    }
    
    for (auto i : A) cout << i / t << ' ';
}