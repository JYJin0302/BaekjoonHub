#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> A(n), dp(n, 1);
    for(auto& i : A) cin >> i;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (A[i] > A[j]) {
                dp[i] += dp[j];
                dp[i] %= mod;
            }
        }
        cout << dp[i] << ' ';
    }
    
}