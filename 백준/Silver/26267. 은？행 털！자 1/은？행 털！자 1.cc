#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    ll ans = 0;
    map<ll, ll> cnt;
    while (n--) {

        ll a, b, c;
        cin >> a >> b >> c;
        cnt[a - b] += c;

        ans = max(ans, cnt[a - b]);
    }
    cout << ans;

}