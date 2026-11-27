#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n;
    cin >> n;
    
    vector<ll> len(n-1), cost(n);
    for(auto&i : len) cin >> i;
    
    for(auto&i : cost) cin >> i;
    
    ll ans = 0;
    ll tc = 1e9+1;
    for (int i = 0; i < n-1; i++){
        tc = min(tc, cost[i]);
        ans += len[i]*tc;
    }
    
    cout << ans;
    
}