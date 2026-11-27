#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    ll cnt[1000001];
    vector<int> A(n);
    for(auto & i : A) cin >> i;
    
    ll t;
    cin >> t;
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int x = A[i];
        if (x <= t && t - x <= 1000000) ans += cnt[t - x];
        cnt[x]++;
    }
    
    cout << ans;
}