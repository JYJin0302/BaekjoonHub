#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
ll dp[3030][3030];
ll getDp(int n, int r){
    if(r==0 || r == n) return 1;
    if (dp[n][r] !=-1) return dp[n][r];
    return dp[n][r] = (getDp(n-1, r) + getDp(n-1, r-1)) % mod;
}


void solve(){
    
    int x, y;cin >> x >> y;
    if (x & 1){
        cout << 0 << '\n';
        return;
    }

    if (x / 2 > y){
        cout << 0 << '\n';
        return;
    }

    memset(dp, -1, sizeof dp);

    int a = x / 2, b = (y - a) / 3;
    ll ans = getDp(a + b, a);
    for(int i = 0; i < a; i++){
        ans= ans * 3 % mod;
    }
    cout << ans << '\n';
    
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}