#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;

ll pow2[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    pow2[0] = 1;
    for (int i = 1; i <= 10000; i++){
        pow2[i] = pow2[i-1] * 2 % mod;
    }
    
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        
        int n; 
        cin >> n;
        
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            ll x;
            cin >> x;
            
            ans += (x * pow2[i-1]) % mod;
            ans += (-x * pow2[n - i] + 10000*mod) % mod;
            ans %= mod;
        }
        
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}