#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){

    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    sort(all(A));

    if (A.back() > k){
        cout << 0 << '\n';
        return;
    }
    if (A[0] <= 0){
        cout << -1 << '\n';
        return;
    }

    ll ans = 1;
    for(int i = 1; i < n; i++){
        ans += (k - A[i]) / A[0];
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