#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){

    int n;
    cin >> n;
    ll L;
    cin >> L;

    vector<ll> ans;

    ll tL = 0;
    ll tR = L;

    vector<pair<ll, ll>> res;

    int rem = n;
    while(tL <= tR){

        if (tR - tL + 1 == rem){
            res.push_back(mp(tL, tR));
            break;
        }

        ll md = (tL + tR)>> 1;

        ll len1 = md - tL;
        ll len2 = tR - md;

        int tl = rem / 2;

        res.push_back(mp(tL, tL + tl - 1));
        rem -= tl;
        tL = md + 1;
    }
    
    for(auto[a,b] : res){
        for(ll i = a; i <= b; i++) cout << i << ' ';
    }
    cout << '\n';


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