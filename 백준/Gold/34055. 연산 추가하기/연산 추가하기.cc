#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


void solve(){

    ll n, L;
    cin >> n >> L;

    vector<pair<ll, ll>> A;
    for(int i =0 ;i < n; i++){
        ll a, b;
        cin >> a>> b;
        A.push_back(mp(a, b));
    }
    sort(all(A));

    vector<ll> res;
    ll pre = 0;
    for(auto[a,b]: A){
        if (a > pre){
            res.push_back(a - pre - 1);
            pre = b;
        }
        else pre = max(pre, b);
    }
    res.push_back(L - pre);
    
    sort(all(res));

    int sn =res.size();
    vector<ll> sR(sn);
    for(int i = sn-1; i >= 0 ;i--){
        sR[i] = res[i] + (i == sn-1 ? 0 : sR[i+1]);
    }

    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;

        ll ans = 0;
        int ix = lower_bound(all(res), x) - res.begin();

        if(ix < sn){
            ans = sR[ix] - 1ll * (sn - ix) * (x - 1);
        }
        cout << ans << '\n';
    }
    

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
