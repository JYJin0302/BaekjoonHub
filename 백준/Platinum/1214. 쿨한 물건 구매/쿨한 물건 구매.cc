#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll d, p, q;
    cin >> d >> p >> q;
    
    if (p < q) swap(q, p);
    
    ll mid = sqrt(1e9);
    if (p >= mid){
        
        ll ans = 2e9;
        for (int i = 0; i <= d/p + 1; i++){
            ll tans = i*p + (d - i*p + q-1) / q * q;
            ans = min(ans, tans);
        }
        
        cout << ans;
    }
    else{
        vector<bool> v(mid+5);
        
        int tx = (d + p - 1) / p;
        ll ans = tx * p;
        v[ans%q] = 1;
        while(1){
            
            tx--;
            if (tx < 0) break;
            ll tans = p*tx + (d - p*tx + q - 1) / q * q;
            ans = min(ans, tans);
            if (v[tans%q]) break;
            v[tans%q] = 1;
        }
        
        cout << ans;
    }
}