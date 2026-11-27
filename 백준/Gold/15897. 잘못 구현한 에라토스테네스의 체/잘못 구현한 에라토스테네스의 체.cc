#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

void solve(){
    
    ll n;
    cin >> n;

    ll ans = n + n - 1;
    ll pre = n - 1;
    n--;

    for(ll i = 2; i * i <= n; i++){
        ll val = n / i;
        ans += val;
        ans += (pre - val) * (i - 1);
        pre = val;
    }

    while(pre* pre > n){
        ans += n / pre;
        pre--;
    }
    cout << ans << '\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
