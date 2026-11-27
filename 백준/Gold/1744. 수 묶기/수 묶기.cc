#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int n;
    cin >> n;

    ll ans = 0;

    vector<ll> pos, neg;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        if (x <= 0) neg.push_back(x);
        else if (x == 1) ans++;
        else pos.push_back(x);
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    for (int i = 0; i < pos.size(); i += 2) {
        if (i + 1 < pos.size()) ans += pos[i] * pos[i + 1];
        else ans += pos[i];
    }

    for (int i = 0; i < neg.size(); i += 2) {
        if (i + 1 < neg.size()) ans += neg[i] * neg[i + 1];
        else ans += neg[i];
    }

    cout << ans;
}