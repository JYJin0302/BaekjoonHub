#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> lst[22];

bool vis[1 << 20];

void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        int val = 0;
        for (int f = 0; f < k; f++) {
            int x;
            cin >> x;
            x--;
            val |= 1 << x;
        }
        lst[k].push_back(val);
        vis[val] = 1;
    }

    int ans = 1 << n;
    queue<int> q, nq;
    for (int i = 1; i <= n; i++) {
        for (auto f : lst[i]) q.push(f);

        while (!q.empty()) {
            int a = q.front();
            q.pop();
            ans--;

            for (int i = 0; i < n; i++) {
                if (a & (1 << i)) {}
                else {
                    int na = a | (1 << i);
                    if (!vis[na]) {
                        vis[na] = 1;
                        nq.push(na);
                    }
                }
            }
        }
        swap(nq, q);
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