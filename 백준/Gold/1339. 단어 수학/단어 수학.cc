#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n;

    vector<ll> base(26);
    for (int i = 0; i < n; i++) {
        cin >> s;
        int size = s.size();
        for (char i : s) {
            base[i - 'A'] += pow(10, size - 1);
            size--;
        }
    }

    ll cnt = 0;
    for (ll i : base) { if (i != 0) cnt++; }

    ll ans = 0;
    for (ll i = 0; i < cnt; i++) {
        int maxx = max_element(base.begin(), base.end()) - base.begin();

        ans += base[maxx] * (9 - i);
        base[maxx] = 0;
    }

    cout << ans;

}