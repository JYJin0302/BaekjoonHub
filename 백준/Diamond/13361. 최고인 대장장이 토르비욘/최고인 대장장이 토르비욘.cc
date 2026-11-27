#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 1e17;
vector<int > num;
int getIdx(int x) {
    return lower_bound(all(num), x) - num.begin();
}
vector<int> adj[501010];
int topo[501010];
pair<ll, ll> dp[501010];
// dp[v] : {v를 사용하지 않았을 때 최댓값, 사용했을 때 최댓값}



void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> edg;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edg.push_back(mp(a, b));
        num.push_back(a);
        num.push_back(b);
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());

    for (auto& [a, b] : edg) {
        a = getIdx(a);
        b = getIdx(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        topo[a]++, topo[b]++;
    }

    queue<int> q;
    for (int i = 0; i < num.size(); i++) {
        if (topo[i] == 1) q.push(i);
    }

    vector<bool> used(n * 2);

    ll ans = 0;
    while (!q.empty()) {

        int a = q.front();
        q.pop();
        used[a] = 1;
        //cout << "Go: " << a << '\n';
        ll v1, v2;
        tie(v1, v2) = dp[a];

        bool isEnd = 1;
        for (auto f : adj[a]) {
            topo[f]--;
            if (topo[f] == 1) q.push(f);
            else if (topo[f] == 0 && used[f]) continue;
            isEnd = 0;
            ll pv1, pv2;
            tie(pv1, pv2) = dp[f];

            ll nv1 = -1, nv2 = -1;
            nv1 = pv1 + v1 + num[f];
            nv2 = max(pv2 + v1 + num[f], pv1 + max(v1, v2) + num[a]);
            dp[f] = mp(nv1, nv2);
           // cout << "upd: " << f << " | " << nv1 << ' ' << nv2 << '\n';
        }

        if (isEnd) {
            ans += max(v1, v2);
        }
    }

    for (int i = 0; i < num.size(); i++) {
        if (topo[i] >= 2) {
            ans += dp[i].first + num[i];
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