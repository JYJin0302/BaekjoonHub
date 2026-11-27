#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    ll ans = 0, ansv = 0;
    for(int i = 0; i < n; i++){
        
        ll tmp = A[i] * (n-i);
        if (tmp > ansv) {
            ansv = tmp;
            ans = A[i];
        }
    }
    
    cout << ansv << ' ' << ans;
}
