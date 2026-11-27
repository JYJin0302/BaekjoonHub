#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string p;
    cin >> p;
    
    int n = p.size();
    
    int res = 0;
    string s;
    
    for (int t = 0; t < n - 1; t++){
        s = p.substr(t, n);
        int m = s.size();
        
        int j = 0;
        
        vector<int> f(m);
        
        for (int i = 1; i < m; i++){
            
            while(j > 0 && s[i] != s[j]){
                j = f[j-1];
            }
                
            if (s[i] == s[j]) j++;
            
            f[i] = j;
            res = max(res, j);
        }
        
    }
    cout << res << '\n';
    
}