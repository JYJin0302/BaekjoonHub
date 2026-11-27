#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T{
    ll num, den;
    
    bool operator<(T& A){
        if (num*A.den != den*A.num) return num*A.den < den*A.num;
        return den < A.den;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, q;
    cin >> n >> q;
    
    vector<ll> A(n+1);
    for(int i = 1; i <= n; i++) cin >> A[i];
        
    vector<T> tmp(10001);
    vector<ll> dp(10001);
    for (int i = 1; i <= 10000; i++){
        if (i <= n) dp[i] = A[i];
        else{
            dp[i] = 1e15;
            for (int j = 1; j <= n; j++){
                dp[i] = min(dp[i], dp[i-j] + A[j]);
            }
        }
        tmp[i].num = dp[i], tmp[i].den = i;
    }
    
    sort(tmp.begin()+1, tmp.end());
    ll mv = tmp[1].den;
    ll val = tmp[1].num;
    
    while(q--){
        
        ll x;
        cin >> x;
        
        if (x <= 10000) cout << dp[x] << '\n';
        else{
            ll v1 = x % mv;
            ll v2 = 10000 / mv * mv;
            
            ll v = v2 + v1;
            if (v > 10000) v -= mv;
            
            ll ans = dp[v] + (x - v) / mv * val;
            cout << ans << '\n';
        }
    }
}