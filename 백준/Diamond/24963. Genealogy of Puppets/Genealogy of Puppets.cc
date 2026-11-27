#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

ll dp[303][303][303];
const int mod = 1e9 + 7;


void solve(){
    
    int n;
    cin >> n;

    vector<pair<int, int>> A(n+1);
    
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        A[i] = mp(x, y);
    }

    dp[n+1][0][0] = 1;

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <=n; j++){
            for(int k = 0; k <= n; k++){
                if (!dp[i+1][j][k]) continue;
                ll val = dp[i+1][j][k];
                //cout << "Caught: " << i+1 << ' '<< j << ' ' << k << " | " << val << '\n';

                if (A[i].x <= 0 && 0 <= A[i].y){
                    if(j + 1 <= n) (dp[i][j+1][k] += val) %= mod;
                    if(k - 1 >= 0) (dp[i][j][k-1] += val * k) %= mod;
                }
                if (A[i].x <= 1 && 1 <= A[i].y){
                    (dp[i][j][k] += val * j * 2) %= mod;
                    if(j - 1 >= 0 && k - 1 >= 0) (dp[i][j - 1][k-1] += val * k * (j-1) * 2) %= mod;
                }
                if (A[i].x <= 2 && 2 <= A[i].y){
                    if(k + 1 <= n) (dp[i][j][k + 1] += val * j * 2) %= mod;
                    if (j - 1 >= 0) (dp[i][j -1 ][k] += val * k * (j - 1) * 2) %= mod;

                    if (j - 1 >= 0) (dp[i][j-1][k] += val * j * (j-1)) %= mod;
                    if (j - 2 >= 0 && k - 1 >= 0) (dp[i][j - 2][k - 1] += val * k * (j - 1) % mod * (j-2)) %= mod;
                }
            }
        }
    }    

    cout << dp[1][1][0] << '\n';
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