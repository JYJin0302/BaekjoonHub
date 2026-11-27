#include <bits/stdc++.h>
using namespace std;

const int mod = 1000;
int dp[501][501];

struct T{
    int x, d, t;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<T> A(n);
    for(auto& i : A){
        cin >> i.x >> i.d >> i.t;
    }
    
    dp[0][0] = 1;
    for (int i = 1; i < n; i++){
        if (A[0].x + A[0].d >= A[i].x) dp[i][0] = 1;
    }
    
    for (int i = 1; i < n; i++){
        
        // ->
        for (int tx = i+1; tx < n; tx++){
            if (A[i].x + A[i].d >= A[tx].x){
                for (int ty = 0; ty < i; ty++){
                    dp[tx][ty] += dp[i][ty];
                    dp[tx][ty] %= mod;
                }
            }
        }
        
        // <-
        for (int ty = 0;ty < i; ty++){
            if (A[ty].x + A[i].d >= A[i].x && A[i].t == 1){
                for (int tx = 0; tx < n; tx++){
                    dp[tx][i] += dp[tx][ty];
                    dp[tx][i] %= mod;
                }
            }
        }
        
        // X
        for(int tx = i+1; tx < n; tx++){
            if (A[i].x + A[i].d >= A[tx].x){
                for (int ty = 0;ty < i; ty++){
                    if (A[ty].x + A[i].d >= A[i].x&& A[i].t == 1){
                        dp[tx][i] -= dp[i][ty];
                        dp[tx][i] = (dp[tx][i] + mod) % mod;
                    }
                }
            }
        }
    }
    
    cout << dp[n-1][n-1];
   
}