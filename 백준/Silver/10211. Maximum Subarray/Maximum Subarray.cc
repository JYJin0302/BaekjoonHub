#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        vector<int> A(n);
        for(auto& i : A) cin >> i;
        
        vector<int> ans(n);
        ans[0] = A[0];
        for (int i = 1; i < n; i++){
            ans[i] = max(A[i], ans[i-1] + A[i]);
        }
        
        cout << *max_element(ans.begin(), ans.end()) << '\n';
    }
}