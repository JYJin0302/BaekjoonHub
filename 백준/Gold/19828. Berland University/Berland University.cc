#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    ll t, n, a, b, k;
    cin >> t>> n >> a>> b>> k;

    ll L = 1, R = t;
    ll ans = 0;
    while(L <= R){
        ll md = (L+R)>>1;
        //cout << L << ' ' << R << ' ' << md << endl;

        // can 'md' student pass?
        ll tot = (n+1)/2 * min(md, a) + n/ 2 * min(md, b);

        if (tot / md >= k){
            ans = md;
            L = md + 1;
        }
        else R = md - 1;
    }
    cout << ans << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
