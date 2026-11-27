#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, q;
    cin >>n  >> q;
    
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    vector<ll> ss(n);
    ss[0] = A[0];
    for(int i = 1; i < n; i++){
        ss[i] = ss[i-1] + A[i];
    }
    vector<ll> dp(n);
    dp[1] = A[0] * A[1];
    for(int i = 2; i < n; i++){
        dp[i] = dp[i-1] + ss[i-1] * A[i];
    }
    
    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        
        cout << dp[b] - dp[a] - (ss[a] - A[a]) * (ss[b] - ss[a])  << '\n';
    }
}