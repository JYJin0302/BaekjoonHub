#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
void solve() {
    
    ll n;
    cin >> n;
 
    string s = to_string(n);
    int sn = s.size();
    string ts(sn, s[0]);
    ll val = stoll(ts);
 
    ll ans = 0;    
    ans += s[0] - '0' - (val > n);
    ans += 9 *(sn - 1);
    cout << ans + 1 << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
