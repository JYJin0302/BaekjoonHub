#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

int n, m;
ll dp[1 << 20];

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1) res = res * b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}
void solve(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        int val = 0;
        while(k--){
            int x;
            cin >> x;
            val += 1 << x-1;
        }
        dp[val]++;
    }

    for(int i = 0; i < m; i++){
        for(int j = 1; j < (1 << m); j++){
            if (j & (1 << i)){
                dp[j] += dp[j ^ (1 << i)];
                dp[j] %= mod;
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < (1 << m); i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if (i & (1 << j)) cnt++;
        }

        if (cnt % 2 == m % 2){
            ans = (ans + fastPow(2, dp[i]) + mod - 1) % mod;
        }
        else{
            ans = (ans + mod - fastPow(2, dp[i]) + 1) % mod;
        }

    }
    cout << ans << '\n';
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
