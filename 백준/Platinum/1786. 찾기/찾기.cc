#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string A, B;
    
    getline(cin, A), getline(cin, B);
    
    int n = A.size(), m = B.size();
    vector<int> f(m);
    
    int curr = 0;
    for (int i = 1; i < m; i++){
        
        while(curr > 0 && B[i] != B[curr]){
            curr = f[curr-1];
        }
        
        if (B[i] == B[curr]) {
            curr++;
            f[i] = curr;
        }
    }
    
    curr = 0;
    int s = 0;
    
    vector<int> ans;
    
    while(s + m <= n){
        
        while(curr < m && A[s + curr] == B[curr]) curr++;
        
        if (curr == m) ans.push_back(s), curr = f[curr-1];
      
        while(curr > 0 && A[s+ curr] != B[curr]) curr = f[curr-1];
        s++;
    }
    
    cout << ans.size() << '\n';
    for (int i : ans) cout << i + 1 << ' ';
}