#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

int M[] = { 0, 31, 28, 31, 30 ,31, 30, 31, 31 ,30, 31, 30, 31 };

void solve() {

    int n;
    cin >> n;

    vector<pair<pair<int, int>, pair<int, int>>> A(n);
    for (auto& i : A) cin >> i.x.x >> i.x.y >> i.y.x >> i.y.y;
    sort(all(A));

    int ans = 0;
    pair<int, int> pre = mp(3, 1);
    int ix = 0;
    while (ix < n && pre <= mp(11, 30)) {

        pair<int, int> mx = pre;
        while (ix < n && A[ix].x <= pre) {
            mx = max(mx, A[ix].y);
            ix++;
        }
        if (mx == pre) break;
        pre = mx;
        ans++;
        //cout << pre.x << ' ' << pre.y << '\n';
    }

    if (pre > mp(11, 30)) {
        cout << ans << '\n';
    }
    else cout << 0 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}