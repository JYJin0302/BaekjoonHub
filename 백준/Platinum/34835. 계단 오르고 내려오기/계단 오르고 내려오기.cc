#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll dp[101010];

void solve(){
    
    int n, k;
    cin >> n >> k;

    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        ll res = dp[i-1];

        if (i == n){
            if (i-k-1 >= 0) res -= dp[i-k-1];
        }
        else if (i-k >= 0) res -= dp[i-k];
        res = (res + dp[i-1] + mod) % mod;
        dp[i] = res;
    }

    cout << (dp[n] - dp[n-1] + mod) % mod << '\n';

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