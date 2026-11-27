#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int h, w;
    cin >> h >> w;

    ll ans = 0;

    stack<pair<int, int>> st;
    for (int i = 0; i < w; i++) {
        int x;
        cin >> x;

        vector<pair<int, int>> res;

        while (!st.empty()) {
            auto [a, b] = st.top();
            if (a <= x) {
                res.push_back(st.top());
                st.pop();
            }
            else break;
        }

        if (res.empty()) {}
        else {
            for (int f = 0; f < res.size() - 1; f++) {
                ans += 1ll * (res[f + 1].x - res[f].x) * (i - res[f + 1].y - 1);
            }
            if (!st.empty()) {
                auto [a, b] = st.top();
                ans += 1ll * (x - res.back().x) * (i - b - 1);
            }
        }

        st.push(mp(x, i));
    }

    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}