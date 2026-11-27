#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    ll n;
    cin >> n;

    ll ans = n*n* 6;
    for(ll i = 1; i <= n;i++){
        ll v = n/i;

        ll tv = sqrt(v);
        for(int j = -5; j <= 5; j++){
            ll tx = tv + j;
            if (tx <= 0 || tx > v) continue;
            ll ty = v / tx;

            ll r = n -  (i * tx * ty);

            if (tx > ty) swap(tx, ty);
            ll val = 2 * i * tx + 2 * i * ty + 2 * tx * ty;

            if (r){
                ll ttx = min(tx, (ll)sqrt(r));
                ll tty = (r + ttx - 1) / ttx;
                val += 2 * (ttx + tty);
            }

            //cout << i << ' ' << tx << ' ' << ty << ' ' << r << " -> " << val << '\n';

            ans = min(ans, val);
        }
    }
    
    cout << ans << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}