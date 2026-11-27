#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int tmp[1001];

const int mod = 1e8;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        x %= k;
        
        for (int j = 0; j < k; j++){
            tmp[j] = dp[j] + dp[(j + k - x)%k];
            tmp[j] %= mod;
        }
        
        swap(dp, tmp);
    }
    
    cout << (dp[0]-1 + mod) % mod;;
}