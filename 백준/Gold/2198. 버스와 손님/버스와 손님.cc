#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int k, n, c;
    cin >> k >> n >> c;

    vector<pair<pair<int, int>, int>> dW, uW;

    for (int i = 0; i < k; i++) {
        int u, v, m;
        cin >> u >> v >> m;

        if (u < v) dW.push_back(mp(mp(u, v), m));
        else {
            u = n + 1 - u;
            v = n + 1 - v;
            uW.push_back(mp(mp(u, v), m));
        }
    }

    sort(all(dW));
    sort(all(uW));

    ll ans = 0;
    vector<ll> landing(n + 1);
    int cur = 0;
    priority_queue<pair<int, int>> pq;

    int ix = 0;
    for (int i = 1; i <= n; i++) {
        while (ix < dW.size() && dW[ix].x.x == i) {
            pq.push(mp(dW[ix].x.y, dW[ix].y));
            cur += dW[ix].y;
            landing[dW[ix].x.y] += dW[ix].y;
            ix++;
        }

        cur -= landing[i];
        ans += landing[i];
        while (cur > c) {
            auto [a, b] = pq.top();
            pq.pop();

            int nd = min(cur - c, b);
            cur -= nd;
            landing[a] -= nd;
            
            if (nd < b) {
                pq.push(mp(a, b - nd));
            }
        }
    }
    while (!pq.empty()) pq.pop();

    swap(dW, uW);
    cur = 0;
    ix = 0;
    landing = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++) {
        while (ix < dW.size() && dW[ix].x.x == i) {
            pq.push(mp(dW[ix].x.y, dW[ix].y));
            cur += dW[ix].y;
            landing[dW[ix].x.y] += dW[ix].y;
            ix++;
        }

        cur -= landing[i];
        ans += landing[i];
        while (cur > c) {
            auto [a, b] = pq.top();
            pq.pop();

            int nd = min(cur - c, b);
            cur -= nd;
            landing[a] -= nd;

            if (nd < b) {
                pq.push(mp(a, b - nd));
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}