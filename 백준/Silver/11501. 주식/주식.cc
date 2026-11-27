#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        vector<ll> A(n);
        for(auto& i : A) cin >> i;
        
        ll ans = 0, mv = 0;
        for(int i = n-1; i >= 0; i--){
            if (A[i] > mv){
                mv = A[i];
            }
            else ans += mv - A[i];
        }
        
        cout << ans << '\n';
    }
    
}