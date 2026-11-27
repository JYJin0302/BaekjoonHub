#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

int dist[101][101];

void solve() {
    memset(dist, -1, sizeof(dist));

    int w, h;
    cin >> w >> h;

    int n, d;
    cin >> n >> d;

    vector<int> A(n), P(n);
    for (auto& i : A) cin >> i;
    for (auto& i : P) cin >> i;

    int pv = 0;
    vector<int> pos(h + 1);
    for (int i = 0; i < n; i++) {
        for (int j = pv; j < A[i]; j++) pos[j] = i + 1;
        pv = A[i];
    }
    pos[h] = n;

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(mp(0, mp(0, 0)));
    while (!pq.empty()) {

        int d = pq.top().first;
        auto [a, b] = pq.top().second;
        pq.pop();

        if (dist[a][b] != -1) continue;
        dist[a][b] = -d;

        if (b + 1 <= h && dist[a][b+1] == -1) {
            // try up
            int p = P[pos[b] - 1];
            int nd = d - p;
            pq.push(mp(nd, mp(a, b + 1)));
        }

        if (b - 1 >= 0 && dist[a][b-1] == -1) {
            // try down
            int p = P[pos[b-1] - 1];
            int nd = d - p;
            pq.push(mp(nd, mp(a, b - 1)));
        }

        if (a + 1 <= w && dist[a+1][b] == -1) {
            // try right
            int p = P[pos[b] - 1];
            int nd = d - p;
            pq.push(mp(nd, mp(a + 1, b)));
        }
    }

    cout << dist[w][d] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}