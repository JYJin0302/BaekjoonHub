#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll n;
    cin >> n;
    
    if (n == 1){
        cout << "koosaga";
        return 0;
    }
    
    ll p_cnt = 0;
    ll d_cnt = 1;
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            
            ll cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            
            p_cnt++;
            d_cnt *= cnt + 1;
            
        }
    }
    
    if (n != 1) {
        p_cnt++;
        d_cnt *= 2;
    }
    
    if ((d_cnt == 4 && p_cnt == 2) || (p_cnt == 1 && d_cnt == 3)) cout << "cubelover";
    else cout << "koosaga";
    
}