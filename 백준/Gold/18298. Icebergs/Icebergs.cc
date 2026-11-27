#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
        
        int p;
        cin >> p;
        
        vector<pair<ll, ll>> A(p);
        for(auto&i : A) cin >> i.x >> i.y;
        
        ll tans = 0;
        for (int j = 2; j < p; j++){
            
            // 삼각형 넓이 0, j-1, j
            
            tans += A[0].x * A[j-1].y + A[j-1].x * A[j].y + A[j].x * A[0].y \
                       - (A[0].y * A[j-1].x + A[j-1].y * A[j].x + A[j].y * A[0].x);
        }
        
        ans += abs(tans);
    }
    
    cout << ans/2;
    
}