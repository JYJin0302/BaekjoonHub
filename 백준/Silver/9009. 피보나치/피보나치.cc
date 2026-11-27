#include <bits/stdc++.h>
using namespace std;

int main(){
    
    
    vector<int> f(46);
    f[1] = 1;
    for (int i = 2; i <= 45; i++) f[i] = f[i-1] + f[i-2];
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<int> ans;
        for (int i = 45; i > 0; i--){
            if (n >= f[i]) {
                n -= f[i];
                ans.push_back(f[i]);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        for(int i : ans) cout << i << ' ';
        cout << '\n';
        
    }
}