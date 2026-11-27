#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll n, k;
    
    map<ll, ll> cnt;
    while(cin >> n){
        
        cin >> k;
        
        int tk = k;
        
        cnt.clear();
        for (int i = 2; i*i <= k; i++){
            int cn = 0;
            while(k % i == 0) cn++, k /= i;
            cnt[i] = cn;
        }
        if (k != 1) cnt[k]++;
        
        ll ans = 1;
        map<ll, ll>::iterator it;
        for (it = cnt.begin(); it != cnt.end(); it++){
            if (it->second != 0){
                ll v = 0, b = it->first;
                
                ll tb = b;
                while(tb <= n){
                    v += n / tb;
                    tb *= b;
                }
                
                v = min(it->second, v);
                ans *= pow(b, v);
            }
        }
        
        cout << ans << '\n';
    }
}