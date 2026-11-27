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

    vector<tuple<int, int, int>> ans;
    int l = 1, r = n;
    int cnt = 99;
    int d = 1;
    while (cnt--) {

        for (int i = 0; i < n; i++) {
            int ni = (i + d) % n;
            ans.push_back(make_tuple(l + i, l + ni, r + i + 1));
        }
        d = d * 2 % n;

        l += n, r += n;
    }

    ans.push_back(make_tuple(r, r, 2000));
    cout << ans.size() << '\n';
    for (auto [a, b, c] : ans) cout << a << ' ' << b << ' ' << c << '\n';

    /*vector<ld> A(2020);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (auto [a, b, c] : ans) {
        A[c] = (A[a] + A[b]) / 2;
    }

    ld tot = 0;
    for (int i = 1; i <= n; i++) tot += A[i];
    tot /= n;

    cout << tot << ' ' << A[2000] << '\n';
    for (int i = l; i <= r; i++) {
        cout << A[i] << ' ';
    }*/

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}