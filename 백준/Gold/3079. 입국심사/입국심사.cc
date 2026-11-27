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
    
    ll l = 1, r = 1e18, ans = r;
    while(l <= r){
        
        ll mid = (l+r)/2;
        ll cnt = 0;
        for (int i = 0; i < n; i++){
            cnt += mid / A[i];
            if (cnt >= m) break;
        }
        
        if (cnt >= m) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout << ans;
}