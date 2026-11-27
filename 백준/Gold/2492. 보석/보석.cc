#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


 

void solve() {

    int n, m, t, k;
    cin >> n >> m >> t >> k;

    vector<pair<int, int>> A(t);

    vector<int> xpos, ypos;
    for (auto& i : A) {
        cin >> i.first >> i.second;
        xpos.push_back(i.first);
        ypos.push_back(i.second);
    }

    sort(all(xpos));
    xpos.erase(unique(all(xpos)), xpos.end());
    sort(all(ypos));
    ypos.erase(unique(all(ypos)), ypos.end());

    pair<int, pair<int, int>> ans;
    for (int i = 0; i < xpos.size(); i++) {
        for (int j = 0; j < ypos.size(); j++) {

            int cnt = 0;
            for (int f = 0; f < t; f++) {

                int tx, ty;
                tie(tx, ty) = A[f];

                if (tx >= xpos[i] && tx <= xpos[i] + k) {
                    if (ty >= ypos[j] && ty <= ypos[j] + k) {
                        cnt++;
                    }
                }

            }
            ans = max(ans, mp(cnt, mp(xpos[i], ypos[j])));
        }
    }

    auto [a, b] = ans.second;
    a = min(a, n - k);
    b = min(b + k, m);
    cout << a << ' ' << b << '\n' << ans.first << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}