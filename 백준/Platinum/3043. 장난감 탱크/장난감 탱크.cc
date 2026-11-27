#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> xpos, ypos;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        xpos.push_back(mp(a, i+1));
        ypos.push_back(mp(b, i+1));
    }

    vector<pair<int, char>> ans, ans2;
    sort(all(xpos));
    for (int i = 0; i < n; i++) {
        int dif = xpos[i].x - (i + 1);
        if (dif == 0) continue;
        if (dif > 0) {
            while (dif--) ans.push_back(mp(xpos[i].y, 'U'));
        }
        else {
            dif *= -1;
            while (dif--) ans2.push_back(mp(xpos[i].y, 'D'));
        }
    }
    reverse(all(ans2));
    for (auto f : ans2) ans.push_back(f);

    sort(all(ypos));
    for (int i = 0; i < n; i++) {
        int dif = ypos[i].x - (i + 1);
        if (dif == 0) continue;
        if (dif > 0) {
            while (dif--) ans.push_back(mp(ypos[i].y, 'L'));
        }
        else {
            dif *= -1;
            while (dif--) ans.push_back(mp(ypos[i].y, 'R'));
        }
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}