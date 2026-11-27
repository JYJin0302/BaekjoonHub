#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    ll c1, c2, c3;
    c1 = 1;
    c2 = c3 = 0;
    for (int i = 0; i < n; i++) {
        ll n1 = 0, n2 = 0, n3 = 0;
        n1 += c1;
        n2 += c1;
        n3 -= c1;

        n2 += c2;
        n1 += -2 * c2;

        n3 += c3;
        n1 += 2 * c3;

        c1 = n1;
        c2 = n2;
        c3 = n3;
    }

    cout << c1 + c2 + c3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
