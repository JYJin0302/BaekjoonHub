#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n = s.size();

    ll cnt = 0;
    for (auto i : s) {
        if (i == 'E') cnt++;
    }

    if (cnt == 0) {
        cout << 0;
        return 0;
    }

    ll ans = n * k;

    vector<int> tmp;

    int ix = 0;
    while (s[ix] == 'P') ix++;

    cnt = 0;
    for (int i = (ix+1)%n; i != ix; i = (i + 1) % n) {
        if (s[i] == 'P') cnt++;
        else {
            if (cnt >= k) {
                ans -= k * (k + 1) / 2;
                ans -= (cnt - k) * k;
            }
            else {
                ans -= cnt * (cnt + 1) / 2;
            }
            cnt = 0;
        }
    }
    if (cnt >= k) {
        ans -= k * (k + 1) / 2;
        ans -= (cnt - k) * k;
    }
    else {
        ans -= cnt * (cnt + 1) / 2;
    }

    cout << ans;

}