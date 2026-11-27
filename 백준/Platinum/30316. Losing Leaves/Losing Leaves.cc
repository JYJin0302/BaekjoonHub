#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[1001010];
int dep[1001010];
vector<int> ans;
int tot = 0;

void dfs(int v) {
    //cout << "Go: " << v << '\n';
    vector<int> tmp;
    for (auto f : adj[v]) {
        dfs(f);
        tmp.push_back(dep[f]);
    }

    if (tmp.empty()) {
        dep[v] = 1;
        tot++;
    }
    else {
        sort(all(tmp));
        reverse(all(tmp));
        dep[v] = tmp[0] + 1;
        for (int i = 1; i < (int)tmp.size(); i++) ans.push_back(tmp[i]);
    }

   // cout << v << " | " << dep[v] << '\n';
}

void solve() {

    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;

        adj[a].push_back(i);
    }

    dfs(0);
    ans.push_back(dep[0]);
    sort(all(ans));

    int cnt = 0;
    for (auto f : ans) {
        if (k >= f) {
            k -= f;
            cnt++;
        }
    }
    cout << tot - cnt << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}