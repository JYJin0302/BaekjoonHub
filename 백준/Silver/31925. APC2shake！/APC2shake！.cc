#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    int n;
    cin >> n;
    vector<pair<int, string>> res;
    for (int i = 0; i < n; i++) {
        
        string a, b, c;
        int v, w;
        cin >> a >> b >> c >> v >>  w;

        bool ok = 1;
        if (b[0] == 'h') ok = 0;
        if (c[0] == 'w') ok = 0;
        if (v == -1 || v > 3) {}
        else ok = 0;

        if (ok) res.push_back(mp(w, a));
        
    }
    sort(all(res));

    vector<string> ans;
    for (int i = 0; i < min(10, int(res.size())); i++) {
        ans.push_back(res[i].y);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto f : ans) cout << f << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}