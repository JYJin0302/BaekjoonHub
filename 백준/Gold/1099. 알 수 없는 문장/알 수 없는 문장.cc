#include <bits/stdc++.h>
using namespace std;

const int INF = 100000;

int main(){
    
    string s;
    cin >> s;
    
    int n, m;
    cin >> n;
    m = s.size();
    
    vector<string> A(n);
    for(auto& i : A)cin >> i;
        
        
    vector<int> dp(m+1, INF);
    dp[0] = 0;
    
    
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < n; j++){
            
            string ts = A[j];
            int tss = ts.size();
            
            if (tss > i) continue;
            
            vector<int> cnt(26), cnts(26);
            for (char c : ts) cnt[c - 'a']++;
            for (int k = 0; k < tss; k++){
                cnts[s[i - 1 - k] - 'a']++;
            }
            
            bool ok = 1;
            for (int k = 0; k < 26; k++) ok &= (cnt[k] == cnts[k]);
            
            if (!ok) continue;
            
            int val = 0;
            for (int k = 0; k < tss; k++){
                val += (s[i - tss + k] != ts[k]);
            }
            
            dp[i] = min(dp[i], dp[i-tss] + val);
            
        }
    }
    
    if (dp[m] == INF) cout << -1;
    else cout << dp[m];
    
}