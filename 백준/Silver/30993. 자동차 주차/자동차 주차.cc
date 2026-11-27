#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

ll f[20];

void solve() {

    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    f[0] = 1;
    for (int i = 1; i <= 15; i++) f[i] = f[i - 1] * i;


    cout << f[n] / (f[a] * f[b] * f[c]);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
