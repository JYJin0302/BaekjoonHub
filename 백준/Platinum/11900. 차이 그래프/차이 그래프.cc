#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define mp make_pair
#define all(x) x.begin(), x.end()

int dist[2020];

void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 1; i < n; i++) cin >> A[i];

    memset(dist, -1, sizeof(dist));
    priority_queue<pair<int, int>> pq;
    pq.push(mp(0, 0));
    while (!pq.empty()) {

        auto [a, b] = pq.top();
        pq.pop();

        if (dist[b] != -1) continue;
        dist[b] = -a;

        for (int j = 1; j < n; j++) {
            if (A[j] == 0) continue;
            int nx = (b + j) % n;
            if (dist[nx] == -1) {
                pq.push(mp(a - A[j], nx));
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        swap(a, b);
        int dif = (b - a + n) % n;
        cout << dist[dif] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}