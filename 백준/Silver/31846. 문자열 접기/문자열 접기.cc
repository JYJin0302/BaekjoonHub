#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, q;
    cin >> n;
    string s;
    cin >> s;

    cin >> q;
    while (q--) {
        int l, r; 
        cin >> l >> r;
        l--, r--;

        int ans = 0;
        for (int i = l; i < r; i++) {
            // l - i, i+1 - r
            int cnt = 0;
            int a = i, b = i + 1;
            while (a >= l && b <= r) {
                if (s[a] == s[b]) cnt++;
                a--, b++;
            }
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}