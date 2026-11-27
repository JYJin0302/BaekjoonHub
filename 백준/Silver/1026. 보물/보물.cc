#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans += A[i]*B[i];
    cout << ans;
    
}