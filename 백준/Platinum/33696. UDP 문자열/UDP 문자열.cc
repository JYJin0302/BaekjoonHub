#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
const int mod = 1e9 + 7;
ll f[20202];
ll dp[5050], dp2[5050];
 
ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex&1) res = res*b % mod;
        b = b*b % mod;
        ex >>= 1;
    }
    return res;
}
 
void solve() {
    
    int n;
    cin >> n;
 
    f[0] = 1;
    for(int i = 1;i <= n *3; i++) f[i] = f[i-1] * i % mod;
 
    for(int i = 1; i <= n; i++){
        dp[i] = f[i*3];
        for(int j = 0; j < 3; j++) dp[i] = dp[i] * fastPow(f[i], mod-2) % mod;
    }
 
    for(int i = 1; i <= n; i++){
        dp2[i] = dp[i];
        for(int j = 1; j < i ;j++){
            dp2[i] -= dp2[j] * dp[i-j] % mod;
            dp2[i] = (dp2[i] % mod + mod) % mod;
        }
    }
 
    cout << dp2[n] << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
