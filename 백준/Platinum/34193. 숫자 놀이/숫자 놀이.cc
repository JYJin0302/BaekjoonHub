#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
 
void solve() {
 
    ll x, n;
    cin >> x>> n;
 
    // x, x+1, .. , x+2n
 
    ll L = x, R = x + n*2;
    ll lim = (L+R)>>1;
    
    if(x == 1){
        ll ans = 0;
        for(ll i = 1; i * i <= R + 1; i++){
            if ((R +1) % i == 0){
                ll v1 = i, v2 = (R+1)/ i;
                if (v1 <= lim && v2 % 2 == 0) ans++;
                if (v2 != v1){
                    if (v2 <= lim && v1 % 2 == 0) ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    else{
        if (n % L == 0){
            cout << 1 << '\n';
        }
        else cout << 0 << '\n';
    }
    
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
