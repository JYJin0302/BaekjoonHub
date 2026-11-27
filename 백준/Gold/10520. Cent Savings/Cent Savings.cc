#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2020][22];

ll f(ll x){
    if (x % 10 >= 5) return (x / 10 + 1) * 10;
    return x / 10 *10;
}

void solve(){

    ll n,m;
    cin >> n >>m;

    vector<ll> A(n+1);
    for(int i = 1;i <= n; i++)cin >>A[i];

    vector<ll> sA(n+1);
    sA[0] = A[0];
    for(int i =1 ; i<= n; i++) sA[i] = sA[i-1] + A[i];

    for(int i = 1; i <= n;i++){
        for(int j = 0; j <= m; j++){
            dp[i][j]= 20020000;
        }
    }
    dp[0][0]= 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){

            dp[i][0] = f(sA[i]);
            for(int k = 1; k <= m; k++){
                dp[i][k] = min(dp[i][k], dp[j][k-1] + f(sA[i] - sA[j]));
            }
        }
    }

    ll ans = 20202020;
    for(int i = 0; i <= m; i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
