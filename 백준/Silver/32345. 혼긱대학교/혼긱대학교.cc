#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

void solve() {

    string s;
    cin >> s;

    int n = s.size();

    vector<ll> len;

    int pos = -1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            len.push_back(i - pos);
            pos = i;
        }
    }
    len.push_back(n - pos);

    if (len.size() == 1) {
        cout << -1 << '\n';
        return;
    }

    ll ans = 1;
    for (int i = 1; i < len.size() - 1; i++) {
        ans = ans * len[i] % mod;
    }
    cout << ans << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) solve();
}