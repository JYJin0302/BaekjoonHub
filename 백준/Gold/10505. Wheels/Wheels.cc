#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {

    ll x, y;
    ll r;

};

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b% a, a);
}

vector<int> adj[1010];
int dir[1010];
bool vs[1010];
ll p[1010], q[1010];

vector<P> A;

void dfs(int v, int pv = -1) {

    for (auto i : adj[v]) if (!vs[i]) {
        vs[i] = 1;

        dir[i] = dir[v] ^ 1;

        ll np = p[v] * A[v].r;
        ll nq = q[v] * A[i].r;

        ll g = gcd(np, nq);
        np /= g;
        nq /= g;

        p[i] = np;
        q[i] = nq;
        dfs(i, v);
    }

}


void solve() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        dir[i] = 0;
        p[i] = q[i] = 0;
        vs[i] = 0;
    }
    vs[0] = 1;
    p[0] = 1;
    q[0] = 1;

    A = vector<P> (n);
    for (auto& i : A) cin >> i.x >> i.y >> i.r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) continue;

            ll c = (A[i].x - A[j].x) * (A[i].x - A[j].x) + (A[i].y - A[j].y) * (A[i].y - A[j].y);
            ll c2 = (A[i].r + A[j].r) * (A[i].r + A[j].r);

            if (c == c2) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        if (p[i] == 0) cout << "not moving\n";
        else {
            if (q[i] != 1) cout << p[i] << '/' << q[i] << ' ';
            else cout << p[i] << ' ';
            if (!dir[i]) cout << "clockwise\n";
            else cout << "counterclockwise\n";
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}