#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    ll n, m, s;
    cin >> n >> m >> s;

    ll s1 = (100 - n) * s * (m+1);
    ll s2 = 100 * s * m;

    cout << min(s1, s2) / 100 << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}