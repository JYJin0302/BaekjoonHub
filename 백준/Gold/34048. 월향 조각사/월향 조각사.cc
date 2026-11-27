#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair



void solve(){
    
    int n;
    cin >> n;
    vector<ll> A(n);
    for(auto& i : A) cin >> i;

    vector<ll> L(n), R(n);
    L[0] =1;
    for(int i = 1; i < n; i++){
        L[i] = min({A[i], i+1ll, L[i-1] + 1});
    }

    R[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        R[i] = min({A[i], (ll)n-i, R[i+1] + 1});
    }

    ll ans = 0;
    for(int i =0 ;i < n; i++){
        ans += min(L[i], R[i]);
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
