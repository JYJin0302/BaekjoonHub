#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int>A(n);
    for(auto&i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    int ans = 0;
    do{
        
        int t = 0;
        for (int i = 1; i < n; i++){
            t += abs(A[i] - A[i-1]);
        }
        
        ans = max(ans, t);
        
    } while(next_permutation(A.begin(), A.end()));
    
    cout << ans;
}