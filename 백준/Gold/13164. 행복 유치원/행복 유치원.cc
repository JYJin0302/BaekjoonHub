#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    k = n-k;
    vector<int> B;
    for(int i = 1; i < n; i++){
        B.push_back(A[i] - A[i-1]);
    }
    sort(B.begin(), B.end());
    
    int ans = 0;
    for(int i = 0; i < k; i++){
        ans += B[i];
    }
    cout << ans;
}