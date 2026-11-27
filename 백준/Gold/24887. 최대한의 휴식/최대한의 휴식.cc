#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    if (*max_element(A.begin(), A.end()) >= m) {
        cout << "Free!";
        return 0;
    }
    
    ll l = 1, r = n-1, ans = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        
        vector<ll> dp(n);
        
        for (int i = 0; i < n; i++){
            dp[i] += A[i];
            if (i > 0) dp[i] = max(dp[i], dp[i-1]);
            if (i + mid < n) {
                dp[i+mid] = max(dp[i+mid], dp[i]);
            }
        }
        
        if (dp[n-1] >= m){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    
    cout << ans-1;
}
