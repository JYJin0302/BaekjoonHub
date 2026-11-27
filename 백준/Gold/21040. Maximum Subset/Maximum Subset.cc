#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> A(n);
    for(auto&i  : A)cin >> i;
    
    sort(A.begin(), A.end());
    
    ll ans = 0;
    ll l = 1, r = 1e9;
    
    while(l <= r){
        
        ll mid = (l+r)/2;
        
        int cnt = 1, idx = 1;
        ll pre = A[0];
        while(idx < n && cnt < k){
            if (A[idx] - pre >= mid) {
                pre = A[idx];
                cnt++;
            }
            
            idx++;
        }
        
        if (cnt == k) {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else r = mid - 1;
        
    }
    
    cout << ans;
}