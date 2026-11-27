#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(){
    
    int n, max_h;
    cin >> n;
    max_h = n/2;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    if (A[n-1] > 0){
        cout << 0;
        return 0;
    }
    
    ll dp[2][5010];  
    int p = 0, c = 1;
    dp[0][0] = (A[0] <= 0);   
    for (int i = 1; i < n; i++){
        
        for (int j = 0; j <= max_h; j++){
            dp[c][j] = 0;
            
            if (A[i] == -1){
                dp[c][j] += dp[p][j];
                if (j > 0) dp[c][j] += dp[p][j-1];
                if (j < max_h) dp[c][j] += dp[p][j+1];
            }
            else if (A[i] == j){
                if (j > 0) dp[c][j] += dp[p][j-1];
                dp[c][j] += dp[p][j];
                if (j < max_h) dp[c][j] += dp[p][j + 1];
            }
            dp[c][j] %= mod;
        }
        swap(p, c);
    }
    
    cout << dp[p][0];
}