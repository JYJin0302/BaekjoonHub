#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;    
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        
        if (A[i] != B[i] && A[i] != 0){
            
            int idx = i;
            while(A[idx] != 0){
                int nidx = A[idx] - 1;
                A[idx] = 0;
                idx = nidx;
                ans++;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        
        if (A[i] != B[i] && A[B[i] - 1] != 0){
            
            int idx = B[i] - 1;
            while(A[idx] != 0){
                int nidx = A[idx] - 1;
                A[idx] = 0;
                idx = nidx;
                ans++;
            }
        }
    }    
    
    for (int i = 0; i < n; i++){
        if (A[i] != B[i]) ans++;
    }
    
    cout << ans;
    
}