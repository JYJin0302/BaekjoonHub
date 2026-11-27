#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
void solve(){
     
    ll L, R;
    cin >> L >> R;
 
    ll val = L ^ R;
 
    ll ans1 = 0, ans2 = 0;
    int ix = 59;
    while(ix >= 0){
        if(val & (1ll << ix)) break;
        ans1 += L & (1ll << ix);
        ans2 += R & (1ll << ix);
        ix--;
    }
    
    while(ix >= 0){
        if (val & (1ll << ix)){
            ans1 += L & (1ll << ix);
            ans2 += R & (1ll << ix);
        }
        else{
            ans1 += 1ll << ix;
        }
        ix--;
    }
 
    cout << ans1 << ' ' << ans2 << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
