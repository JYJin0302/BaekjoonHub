#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool vis[20002020];
bool tans[20002020];
void solve() {

    int lim = 20000000;
    queue<int> q;
    vector<int> res;
    q.push(1);
    while (!q.empty()){
        ll a = q.front();
        q.pop();
        res.push_back(a);

        if (a * 15 <= lim && !vis[a * 15]) {
            vis[a * 15] = 1;
            q.push(a * 15);
        }

        if (a % 5 == 0) {
            ll na = a / 5 * 9;
            if (na <= lim && !vis[na]) {
                vis[na] = 1;
                q.push(na);
            }
        }
        if (a % 3 == 0) {
            ll na = a / 3 * 25;
            if (na <= lim && !vis[na]) {
                vis[na] = 1;
                q.push(na);
            }
        }
    }

    sort(all(res));

    priority_queue<pair<ll, ll>> pq;
    for (int i = 1; i <= 1000000; i++) {
        if ((i % 3 != 0) && (i % 5 != 0)) {
            pq.push(mp(-i * res[0], 0));
        }
    }

    vector<ll> ans;
    while (ans.size() <= 100000) {
        auto [a, b] = pq.top(); pq.pop();
        a *= -1;
        ans.push_back(a);
        if (b + 1 < res.size()) {
            ll na = a / res[b] * res[b + 1];
            pq.push(mp(-na, b + 1));
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << ans[x - 1] << '\n';
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}