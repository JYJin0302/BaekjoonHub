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
    
    vector<pair<ll, ll>> B;
    for(int i =0 ; i < n;i++){
        int k;
        cin >> k;

        vector<ll> A(k);
        for(auto& f : A) cin >> f;
        sort(all(A));
        B.push_back(mp(A.back(), k));
    }

    ll mx = 0;
    ll ans = 0;
    for(auto[a,b]: B) mx = max(mx, a);
    for(auto[a,b]: B){
        ans += (mx - a) * b;
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
