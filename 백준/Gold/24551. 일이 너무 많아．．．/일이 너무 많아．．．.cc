#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll n;
    cin >> n;
    
    vector<ll> A = {11};
    ll v = 111;
    
    while(v <= n){
        bool ok = 1;
        for (auto i : A){
            if (v % i == 0) ok = 0;
        }
        if (ok) A.push_back(v);
        v = v*10 + 1;
    }
    
    int m = A.size();
    
    ll ans = 0;
    for (int i = 1; i < (1 << m); i++){
        ll tn = n;
        v = 1;
        
        int cnt = 0;
        for(int j = 0; j < 7; j++){
            if (i & (1 << j)) {
                cnt++;
                v *= A[j];
                tn /= A[j];
            }
        }
        
        if (tn != 0){
            if (cnt % 2) ans += n / v;
            else ans -= n/v;
        }
    }
    cout << ans;
}