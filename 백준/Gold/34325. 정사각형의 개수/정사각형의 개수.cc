#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
ll cnt[1001010];
ll dp[1001010];

void solve() {

    int n;
    cin >> n;
    ll k;
    cin >> k;

    cnt[1] = 1;
    cnt[2] = 4;

    for(ll i =3; i <= n; i++){
        cnt[i] = i*i % mod;
        
        dp[i] = dp[i-2] + i-2;
        dp[i] %= mod;
        cnt[i] += 4 * dp[i];
        cnt[i] %= mod;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += cnt[i];
        ans *= k;
        ans %= mod;
    }
    cout << ans << '\n';
    

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}