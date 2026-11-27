#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll a, b, c, d;
string sa, sb;
map<pair<int, int>, bool> chk;

void F(int msk) {
    vector<int> cntA(10), cntB(10);
    ll val = 0;
    for (int i = 0; i < sa.size(); i++) {
        if (msk & (1 << i)) {
            val = val * 10 + sa[i] - '0';
            if (val == 0) return;
        }
        else {
            cntA[sa[i] - '0']++;
        }
    }

    __int128 tmp = val;
    tmp *= d;

    __int128 t2 = tmp / c;
    if (t2 * c == tmp) {}
    else return;
    tmp = t2;

    ll tbb = tmp / ll(1e18);
    if (tmp / ll(1e18)) return;
    ll tb = tmp;

    string nb = to_string(tb);

    vector<bool> chk(20);
    int cur = 0;
    for (int j = 0; j < sb.size(); j++) {
        if (cur < nb.size() && nb[cur] == sb[j]) {
            cur++;
        }
        else {
            cntB[sb[j] - '0']++;
        }
    }
    if (cur < nb.size()) return;

    for (int j = 0; j <= 9; j++) if (cntB[j] != cntA[j]) return;

    cout << "possible\n";
    cout << val << ' ' << tb << '\n';
    exit(0);

}

void solve() {

    cin >> a >> b >> c >> d;
    ll g = gcd(c, d);
    c /= g, d /= g;

    sa = to_string(a);
    sb = to_string(b);
    int n = sa.size();
    for (int i = 1; i < (1 << n); i++) {
        F(i);
    }
    cout << "impossible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}