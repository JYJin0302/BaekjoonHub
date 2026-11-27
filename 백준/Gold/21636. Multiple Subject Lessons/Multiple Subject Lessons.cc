#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll C[33][33];

ll nCr(int n, int r){
    if (n == r || r == 0) return C[n][r] = 1;
    if (n < r) return C[n][r] = 0;
    if (C[n][r] != -1) return C[n][r];

    return C[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
}

void solve(){
    
    int n, k;
    cin >> n >> k;

    memset(C, -1, sizeof C);

    vector<ll> dp(n+1), ndp(n+1);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        ndp =vector<ll>(n+1);

        for(int j = 0; j < n; j++){
            for(int f = 1; j + f * i <= n; f++){
                ndp[j + f*i] += dp[j] * nCr(k+f -1, f);
            }
        }

        for(int j = 0; j <= n; j++) dp[j] += ndp[j];
        // for(auto f: dp) cout <<f  << ' ';
        // cout << '\n';
    }


    cout << dp[n] << '\n';




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
