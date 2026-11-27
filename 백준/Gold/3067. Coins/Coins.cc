#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vector<int> c(n);
        for(auto& i : c) cin >> i;
        
        int m;
        cin >> m;
        
        vector<int> dp(m+1);
        dp[0]= 1;
        
        for (auto i : c){
            for (int j = i; j <= m; j++){
                dp[j] += dp[j-i];
            }
        }
        
        cout << dp[m] << '\n';
    }
}