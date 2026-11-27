#include <bits/stdc++.h>
using namespace std;


int dp[1 << 15];
pair<int, int> ap[1 << 15];


bool isB(int v, int i){
    return v & (1 << i);
}

int solve(int v){
    
    if (dp[v] != -1) return dp[v];
    
    for (int i = 0; i < 15; i++){
        if (isB(v, i)) {
            
            int tv = v;
            for (int j = i; j >= 0; j--){
                tv ^= (1 << j);
                if (solve(tv) == 0) {
                    ap[v] = {i+1, i-j+1};
                    return dp[v] = 1;
                }
            }
            
        }
    }
    return dp[v] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    
    int t;
    cin >> t;
    while(t--){
        
        string s;
        cin >> s;
        
        int v = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            v = v*2 + (s[i] == 'H');
        }
        if (!solve(v)) cout << "NO\n";
        else{
            cout << "YES " << ap[v].first << ' ' << ap[v].second << '\n';
        }
    }
}