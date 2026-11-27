#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<int> A(m);
    for(auto& i : A) cin >> i;
    
    bool dp[2001];
    for (int i = 1; i <= 2000; i++){
        
        bool ok = 0;
        for (int a : A) {
            if (i - a >= 0) ok |= !dp[i-a];
        }
        dp[i] = ok;
    }
    
    int cyc = 2;
    
    while(1){
        
        bool ok = 1;
        for (int j = 2000; j > 1000; j--){
            ok &= (dp[j] == dp[j-cyc]);
        }
        
        if (ok) break;
        cyc++;
    }
    
    int ans = 0;
    if (n <= 2000) {
        for (int i = 1; i <= n; i++) ans += !dp[i];
        cout << ans;
    }
    else{
        for (int i = 1; i <= 2000; i++){
            ans += !dp[i];
        }
        
        int cyc_v = 0;
        for(int i = 0; i < cyc; i++){
            cyc_v += !dp[2000-i];
        }
        
        ans += cyc_v * ((n - 2000) / cyc);
        
        for (int i = 0; i < ((n - 2000) % cyc); i++){
            ans += !dp[2001-cyc + i];
        }
        
        cout << ans;
    }
    
}