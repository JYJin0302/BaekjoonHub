#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,x;
    cin >> n >> x;
    
    x -= 1000*n;
    x /= 4000;
    
    int ans = 0;
    vector<int> A(n);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ans += b;
        A[i] = max(0, a - b);
    }
    
    sort(A.rbegin(), A.rend());
    for(int i = 0; i< x; i++) ans += A[i];
    
    cout << ans;
}