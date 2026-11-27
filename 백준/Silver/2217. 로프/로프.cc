#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    sort(A.begin(), A.end());
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, A[i] * (n-i));
    }
    cout << ans;
}