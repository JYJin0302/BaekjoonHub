#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()



void solve() {

    ll n;
    cin >> n;

    vector<ll> tmp = { 1 };
    while (tmp.back() <= n) {
        tmp.push_back(tmp.back() * 2);
    }

    int cnt = 0;
    for (int i = tmp.size() - 1;n && i >= 0; i--) {
        while (n >= tmp[i] - 1) {
            n -= tmp[i] - 1;
            cnt++;
        }
    }
    cout << cnt - 1 << '\n';

}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}