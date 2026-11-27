#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int dp[202][202];
int tmp[202][202];

void solve(){
    
    int n, u, v;
    cin >> n >> u >> v;

    int ta= 0 ;
    int tb = 0;

    vector<pair<int, int>> A;
    for(int i =0 ; i< n; i++){
        int a, b;
        cin >> a>> b;

        A.push_back(mp(a, b));
        ta += a;
        tb += b;
    }

    if (ta < u || tb < v){
        cout << -1 << '\n';
        return;
    }
    
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(auto[a,b] : A){
        for(int i = 0; i <= u; i++){
            for(int j = 0; j <= v; j++){
                tmp[i][j] = dp[i][j];
            }
        }
        for(int i = 0; i <= u; i++){
            for(int j = 0; j <= v; j++){
                if (dp[i][j] == -1) continue;
                int ni = min(u, i + a);
                int nj = min(v, j + b);

                if (tmp[ni][nj] == -1 || tmp[ni][nj] > dp[i][j] + 1){
                    tmp[ni][nj] = dp[i][j] + 1;
                }
            }
        }
        swap(tmp, dp);
    }

    cout << dp[u][v] << '\n';



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