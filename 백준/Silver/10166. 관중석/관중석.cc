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

void solve() {

    int d1, d2;
    cin >> d1 >> d2;

    set<pair<int, int>> st;
    for (int i = d1; i <= d2; i++) {
        for (int j = 1; j < i; j++) {
            int ti = i, tj = j;
            int g = gcd(ti, tj);
            ti /= g, tj /= g;
            st.insert(mp(ti, tj));
        }
    }

    cout << st.size() + 1 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}