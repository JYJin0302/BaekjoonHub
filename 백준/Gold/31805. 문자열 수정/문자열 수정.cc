#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> idx[26];

void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;

    string ts = s;

    for (int i = 0; i < n; i++) {
        idx[s[i] - 'a'].push_back(i);
    }

    int mx = n / 2 + 1;
    for (int i = 0; i < 26; i++) {
        if (idx[i].size() >= mx) {
            cout << -1;
            return;
        }
    }

    vector<pair<int, int>> ans;

    for (int i = 0; i < n / 2; i++) {
        vector<pair<int, int>> cnt;
        for (int f = 0; f < 26; f++) {
            if (!idx[f].empty()) {
                cnt.push_back(mp(idx[f].size(), f));
            }
        }
        sort(cnt.rbegin(), cnt.rend());

        int a = cnt[0].y, b = cnt[1].y;
        int ia = idx[a].back(); idx[a].pop_back();
        int ib = idx[b].back(); idx[b].pop_back();

        ans.push_back(mp(ia, ib));
        swap(s[ia], s[ib]);
    }
    if (n & 1) {
        int ix = 0;
        while (ix < 26 && idx[ix].empty()) ix++;

        int ia = idx[ix][0];
        for (int j = 0; j < n; j++) {
            if (s[j] != s[ia] && ts[j] != s[ia]) {
                ans.push_back(mp(j, ia));
                swap(s[j], s[ia]);
                break;
            }
        }
    }
    //cout << "RES: " << s << '\n';

    cout << ans.size() << '\n';
    for (auto& [a, b] : ans) if (a > b) swap(a, b);
    sort(all(ans));
    for (auto f : ans) cout << f.x+1 << ' ' << f.y+1 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}