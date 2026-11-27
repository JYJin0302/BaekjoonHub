#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    ll mod = 1234567891;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<ll> mul(n);
    mul[0] = 1;
    for (int i = 1; i < n; i++){
        mul[i] = (mul[i-1]*31)%mod;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll t = s[i] - 'a' + 1;
        ans = (ans + t * mul[i])% mod;
    }
    cout << ans;
}