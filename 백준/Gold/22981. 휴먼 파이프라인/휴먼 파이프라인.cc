#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    sort(A.begin(), A.end());
    
    ll ans = k;
    for(ll i = 0; i < n-1; i++){
        ll v = (i+1) * A[0] + (n - i - 1) * A[i+1];
        ans = min(ans, (k + v - 1) / v);
    }
    cout << ans;
}