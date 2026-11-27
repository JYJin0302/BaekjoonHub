#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll n;
    cin >> n;
    
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    if (n <= 2) {
        cout << 0;
        return 0;
    }
    
    ll L = 0, R = 1e9;
    
    ll ans = 1e18;
    while(L <= R){
        
        ll m1 = (2*L+R)/3, m2 = (L+2*R)/3;
        
        ll t1 = 0;
        for (ll i = 1; i < n; i++){
            t1 += abs(i * m1 - A[i]);
        }
        
        ll t2 = 0;
        for (ll i = 1; i < n; i++){
            t2 += abs(i * m2 - A[i]);
        }
        
        ans = min({ans, t1, t2});
        if (t1 > t2){
            L = m1 + 1;
        }
        else R = m2 - 1;
        
    }
    
    cout << ans;
    
}