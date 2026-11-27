#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, ans = 0;
    cin >> n >> m;
    
    vector<ll>cnt(m);
    cnt[0] = 1;
    
    int pv = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        pv = (pv + x) % m;
        ans += cnt[pv];
        cnt[pv]++;
    }
    
    cout << ans;
}