#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int cnt[1001010];
bool chk(int x) {
    string ts = to_string(x);
    if (ts.size() <= 2) return 0;
    int ix = 1;
    while (ix < ts.size() && ts[ix] > ts[ix - 1]) ix++;
    if (ix == ts.size() || ix == 1) return 0;

    while (ix < ts.size() && ts[ix] < ts[ix - 1]) ix++;
    return ix == ts.size();

}

void solve() {

    int l, r;
    cin >> l >> r;
    cout << cnt[r] - cnt[l - 1] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 1e6; i++) {
        cnt[i] = chk(i) + cnt[i - 1];
        //if (chk(i)) cout << i << '\n';
    }

    int t = 1;
     cin >> t;
    while (t--) solve();
}