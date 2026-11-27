#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
int n;
ll dp[1001010];
ll getDp(int x){
    if (dp[x] != -1) return dp[x];

    ll res = 0;

    // x , x + 1
    int k = 1;
    int prev = x + 1;
    while(x * k <= n){
        int b = x * k;
        for(int i = 0; i < 3; i++){
            int nx1 = b + i;

            if (nx1 <= prev) continue;
            if (nx1 > n + 1) break;
            prev = nx1;
            res = (res + getDp(nx1 - 1)) % mod;
        }
        k++;
    }
    if (prev != n+1){
        res = (res +  getDp(n)) % mod;
    }

    return dp[x] = res;
}

void solve(){
    
    cin >> n;

    memset(dp, -1, sizeof dp);
    
    dp[n] = 1;
    for(int i = n; i >= 1; i--) getDp(i);
    ll res = dp[1];

    cout << res * n % mod << '\n';

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