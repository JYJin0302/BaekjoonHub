#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll dp[1010][1010];

ll getDP(int x, int k){
    if (x == k || k == 0) return 1;
    if (dp[x][k] != -1) return dp[x][k];
    return dp[x][k] = (getDP(x-1, k) + getDP(x-1, k-1)) % mod;
}

void solve(){
    
    int n, k;
    cin >> n >> k;
    cout << getDP(n, k) << '\n';

}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof dp);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}