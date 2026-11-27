#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, c;
    cin >> n >> c;

    set<pair<int, int>> st;

    for (int i = 1; i <= c; i++) {
        int x;
        cin >> x;
        st.insert(mp(x, i));
    }

    for(int i = 0; i < n/2; i++){
        auto iter = --st.end();
        auto [a, b] = *iter;
        iter = --st.erase(iter);

        auto [c, d] = *iter;
        st.erase(iter);
        //cout << a << ' ' << b << " | " << c << ' ' << d << '\n';
        cout << b << ' ' << d << '\n';
        a--, c--;
        if (a) st.insert(mp(a, b));
        if (c) st.insert(mp(c, d));
    }


}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}