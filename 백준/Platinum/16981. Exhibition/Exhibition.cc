#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<ll, ll>> A(n);
    for(auto& i : A) cin >> i.y >> i.x;
    
    sort(A.begin(), A.end());
    
    vector<ll> C(m);
    for(auto& i : C) cin >> i;
    
    sort(C.rbegin(), C.rend());
    
    
    ll ans = 0;
    ll L = 1, R = m;
    while(L <= R){
        
        ll mid = (L+R)/2;
        
        ll cnt = mid - 1, pre = 0;
        
        for (int i = 0; i < n; i++){
            if (cnt < 0) break;
            if (A[i].x >= pre && A[i].y <= C[cnt]){
                cnt--;
                pre = A[i].x;
            }
        }
        
        if (cnt < 0) {
            ans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    
    cout << ans;
    
}