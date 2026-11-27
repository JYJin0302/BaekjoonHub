#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k;
const ll mod = 1e9+7;

struct Matrix{
    ll x1, y1;
    ll x2, y2;
};

Matrix dp[70];

Matrix mult(Matrix& A, Matrix& B){
    Matrix res = {0, 0, 0, 0};
    res.x1 = (A.x1*B.x1 % mod+ A.y1*B.x2 % mod) % mod;
    res.y1 = (A.x1*B.y1 % mod+ A.y1*B.y2 % mod) % mod;
    res.x2 = (A.x2*B.x1 % mod+ A.y2*B.x2 % mod) % mod;
    res.y2 = (A.x2*B.y1 % mod+ A.y2*B.y2 % mod) % mod;
    return res;
}

ll fastPow(ll base, ll ex){
    ll tp = base%mod, res = 1;
    while(ex){
        if (ex % 2) res *= tp;
        res %= mod;
        tp = (tp*tp) % mod;
        ex /= 2;
    }
    
    return res;
}

void init(){
    dp[0] = {0, 1, (n-1)%mod, (n-2)%mod};
    
    for (int i = 1; i <= 66; i++){
        dp[i] = mult(dp[i-1], dp[i-1]);
    }
}

Matrix fastPow(ll x){    
    Matrix res = {0, 0, 0, 1};
    if (x == 0) return res;
    
    res = dp[0];
    x--;
    int ix = 0;
    while(x){
        if (x % 2) {
            res = mult(res, dp[ix]);
        }
        ix++;
        x /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    init();
    
    ll ans = 1;
    ll pa = -1, pb = -1;
    for (int i = 0; i < k; i++){
        
        ll a, b;
        cin >> a >> b;
        
        if (i == 0){
            ans *= fastPow(n-1, a-1);
        }
        else{
            Matrix tmp = fastPow(a - pa-1);
            
            if (b == pb) ans *= tmp.x2;
            else ans *= tmp.y2;
        }
        ans %= mod;
        pa = a;
        pb = b;
    }
    
    ans = ans * fastPow(n-1, m-pa) % mod;
    
    cout << ans;
}