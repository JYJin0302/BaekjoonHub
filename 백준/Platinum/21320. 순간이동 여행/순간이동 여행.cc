#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll dp[3030];


void solve(){
    
    int n, k;
    cin >> n >> k;

    dp[1] = 0;
    dp[2] = 0;
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= i-2; j++){
            dp[i] += 2 + 2 * dp[j];
            dp[i] %= mod;
        }
    }

    ll ans = 0;
    if (k == 1){
        for(int i = 1; i < n; i++){
            ans += 1 + dp[i];
        }
        ans %= mod;
    }
    else if (k == n){
        ans = dp[n];
    }
    else {
        ans += 1 + dp[n-k];
        for(int i = n-k; i < n-1; i++){
            ans += 1 + dp[i];
        }
        for(int i = 1; i < n - 1; i++){
            ans += 1 + dp[i];
        }
        ans %= mod;
    }
    cout << ans << '\n';


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
