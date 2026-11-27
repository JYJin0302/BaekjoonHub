#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n, h;
    cin >> n >> h;

    bool ok = 1;
    ll ans = 0;
    for(int i =0 ; i< n; i++){
        ll a, b, c;
        cin >> a>> b>> c;

        ll val = 1e9 + 10;;
        bool found = 0;
        if (a <= h){
            val = min({val, b, c});
            found = 1;
        }
        if (b <= h){
            val = min({val, a, c});
            found = 1;
        }
        if (c <= h){
            val = min({val, a, b});
            found = 1;
        }

        if (!found) ok = 0;
        else ans += val;
    }

    if (ok) cout << ans << '\n';
    else cout << "impossible\n";
    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
