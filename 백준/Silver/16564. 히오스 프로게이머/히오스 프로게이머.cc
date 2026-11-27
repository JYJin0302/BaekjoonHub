#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> A(n);
    for(auto& i : A)cin >> i;
    
    ll L = 1, R = 2e9, ans = 1;
    while(L <= R){
        ll mid = (L+R)/2;
        
        ll val = 0;
        for (ll i : A) val += max(0ll, mid - i);
        
        if (val <= k) {
            ans = max(ans, mid);
            L = mid+1;
        }
        else R = mid-1;
    }
    
    
    cout << ans;
}