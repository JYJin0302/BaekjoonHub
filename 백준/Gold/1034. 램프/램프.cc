#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    int k;
    cin >> k;
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        
        int tcnt = 0;
        vector<bool> tmp(m);
        for (int j = 0; j < m; j++){
            if (A[i][j] == '0') tmp[j]=1, tcnt++;
        }
        
        if (tcnt <= k && (k - tcnt)%2 == 0){
            
            int tans = 0;
            for (int a = 0 ; a < n; a++){
                bool ok = 1;
                for (int b = 0; b < m; b++){
                    if (A[a][b] == '0' && !tmp[b]) ok = 0;
                    if (A[a][b] == '1' && tmp[b]) ok = 0;
                }
                tans += ok;
            }
            
            ans = max(ans, tans);
        }
        
    }
    cout << ans;
}