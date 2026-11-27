#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> A(n), B(n);
    for(auto& i : A) cin >> i;
    
    B[0] = A[0];
    for(int i = 1; i < n; i++) B[i] = B[i-1] + A[i];
    
    int idx = 0;
    ll val = 0;
    vector<ll> dp(n);
    for(int i = 0; i < n; i++){
        while(B[i] - B[idx] + A[idx] - A[i] >= k) {
            val = max(val, dp[idx]);
            idx++;
        }
        
        dp[i] = max(0ll, B[i] - B[idx] + A[idx] - k) + val;
    }
    
    cout << *max_element(dp.begin(), dp.end());
}