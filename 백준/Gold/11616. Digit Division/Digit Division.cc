#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    int v = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        v = v*10 + (s[i] - '0');
        v %= m;
        
        if (v == 0) cnt++;
    }
    
    ll mod = 1e9+7;
    cnt--;
    if (v != 0) cout << 0;
    else{
        
        ll ans = 1;
        while(cnt--) ans = ans*2 % mod;
        cout << ans;
    }
}