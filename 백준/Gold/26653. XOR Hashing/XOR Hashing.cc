#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

const ll mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

    

    ll tn = (1 << n);

    if (m > tn) {
        cout << 1;
        return 0;
    }

    ll ans = 1;
    for (int i = 0; i < m; i++) {
        ans = ans * (tn - i) % mod;
        ans = ans * fastPow(tn, mod - 2, mod) % mod;
    }
    cout << (1-ans+mod) % mod;

}