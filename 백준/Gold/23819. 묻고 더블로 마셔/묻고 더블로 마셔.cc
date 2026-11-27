#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, mod;
vector<vector<ll>> dp[35];

vector<vector<ll>> mult(vector<vector<ll>>& a, vector<vector<ll>>& b){
    
    vector<vector<ll>> res(k, vector<ll>(k));
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            ll val = 0;
            for(int x = 0; x < k; x++){
                val += a[i][x]*b[x][j];
                val %= mod;
            }
            res[i][j] = val;
        }
    }
    
    return res;
}

void init(){
    
    vector<vector<ll>> tmp(k, vector<ll>(k));
    for (int i = 0; i < k; i++){
        tmp[k-1][i] = 1;
        if (i > 0) tmp[i-1][i] = 1;
    }
    dp[0] = tmp;
    
    for(int i = 1; i < 33; i++){
        dp[i] = mult(dp[i-1], dp[i-1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
        
    vector<ll> A(k);
    for(auto& i : A) cin >> i;
    
    cin >> mod;
    
    if (n <= k) {
        cout << A[n-1];
        return 0;
    }
    
    init();
    
    ll target = n - k - 1;
    vector<vector<ll>> tmp = dp[0];
    
    int ix = 0;
    while(target){
        if (target % 2) tmp = mult(tmp, dp[ix]);
        ix++;
        target /= 2;
    }
    
    ll ans = 0;
    for (int i = 0; i < k; i++){
        ans += A[i]*tmp[k-1][i];
        ans %= mod;
    }
    cout << ans;
}