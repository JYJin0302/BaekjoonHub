#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int Candy[30303];
int root[30303];
int sz[30303];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> Candy[i];
        root[i] = i;
        sz[i] = 1;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        a = find(a), b = find(b);
        if (a == b) continue;
        root[b] = a;
        sz[a] += sz[b];
        Candy[a] += Candy[b];
    }

    vector<pair<int, int>> V;
    for (int i = 0; i < n; i++) {
        if (root[i] == i) {
            V.push_back(mp(sz[i], Candy[i]));
        }
    }

    //for (auto f : V) cout << f.first << ' ' << f.second << '\n';

    vector<int> dp(k);
    for (auto& [a, b] : V) {
        for (int j = k - 1; j >= a; j--) {
            dp[j] = max(dp[j], dp[j - a] + b);
        }
    }
    cout << dp[k - 1];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}