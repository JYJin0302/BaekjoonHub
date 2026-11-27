#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const ll mod = 4e9+9;

ll n, k, l;

vector<vector<ll>> dp;

vector<vector<ll>> mult(vector<vector<ll>>& a, vector<vector<ll>>& b){
    vector<vector<ll>> res(l, vector<ll>(l));
    for (int i = 0; i < l; i++){
        for (int j = 0; j < l ;j ++){
            for (int k = 0; k < l; k++){
                res[i][j] += a[i][k]*b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

int main(){
    
    cin >> n >> l >> k;
    l--;
    
    if (n == 0) {
        cout << 1;
        return 0;
    }
    if (n == 1){
        cout << k;
        return 0;
    }
    n-=2;
    
    dp = vector<vector<ll>>(l, vector<ll>(l));
    
    for (int i = 0; i < l; i++){
        for (int j = 0; j < l; j++){
            if (j == 0) dp[i][j] = k-1;
            else if (i+1 == j) dp[i][j] = 1;
        }
    }
    vector<vector<ll>> ans = dp;
    
    for (int i = 0; i < 30; i++){
        if (n % 2 == 1) ans = mult(ans, dp);
        n >>= 1;
        dp = mult(dp, dp);
    }
    
    ll res = 0;
    for (int i = 0; i< l ;i++){
        res += ans[0][i];
        res %= mod;
    }
    cout << res*k % mod;
}