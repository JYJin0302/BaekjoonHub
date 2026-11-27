#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    ll n, p;
    cin >> n >> p;

    if (n % p == 0) {
        cout << 0 << '\n';
        return;
    }

    if (n % 2 == p % 2) {
        ll len = n / 2 - p / 2;
        ll ans = 1;
        ans += 2 * (len / p);
        cout << n - ans * p << '\n';
    }
    else if (n % 2 == 0) {
        ll ans = (n / 2) / p;
        ans *= 2;
        cout << n - ans * p << '\n';
    }
    else cout << 0 << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}