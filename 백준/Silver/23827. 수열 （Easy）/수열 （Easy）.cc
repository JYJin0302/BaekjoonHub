#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

void solve(){
    
    int n;
    cin >> n;
    vector<ll> A(n);
    for(auto& i : A) cin >> i;

    ll s = 0;
    ll ans = 0;
    for(auto f : A){
        ans += s * f % mod;
        ans %= mod;
        s = (s + f) % mod;
    }
    cout << ans << '\n';
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