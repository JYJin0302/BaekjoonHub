#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<ll> A(n+1);
    
    A[0] = 1;
    A[1] = 1;
    
    for (int i = 2; i <= n; i++){
        A[i] = A[i-1] + A[i-2];
    }
    
    int ans = 1;
    int pre = 1;
    while(m--){
        int x;
        cin >> x;
        
        ans *= A[x - pre];
        pre = x + 1;
    }
    ans *= A[n - pre + 1];
    
    cout << ans;
}