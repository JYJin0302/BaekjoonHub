#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    vector<ll> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    
    int q;
    cin >> q;
    while(q--){
        
        ll a, b, k;
        cin >> a >> b >> k;
        
        ll l = 1, r = pow(2, 31) - 1;
        
        int ans = -1;
        
        while(l <= r){
            
            ll mid = (l+r)/2;
            
            int res = 0;
            res += upper_bound(A.begin(), A.begin() + a, mid) - A.begin();
            res += upper_bound(B.begin(), B.begin() + b, mid) - B.begin();
            
            if (res >= k){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        int i1, i2;
        i1 = lower_bound(A.begin(), A.begin() + a, ans) - A.begin();
        i2 = lower_bound(B.begin(), B.begin() + b, ans) - B.begin();
        
        if (i1 < n && A[i1] == ans) cout << 1 << ' ' << i1+1 << '\n';
        else cout << 2 << ' ' << i2+1 << '\n';
    }
}