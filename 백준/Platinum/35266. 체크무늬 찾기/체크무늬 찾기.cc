#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()
 
char G[2020][2020];
int U[2020][2020];
 
void solve(){
 
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> G[i][j];
        }
    }
 
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (i == 1 || G[i][j] == G[i-1][j]) U[i][j] = 1;
            else U[i][j] = U[i-1][j] + 1;
        }
    }
 
    ll ans = 0;
    for(int i =1;i <= n ;i++){
        vector<pair<int, int>> stk;
        int S = 0;
        for(int j = 1; j <= n; j++){
            int val = U[i][j];
            if (j > 1 && G[i][j] == G[i][j-1]) {
                stk.clear();
                S = 0;
            }
            int cnt = 1;
            while(!stk.empty() && stk.back().x > val){
                cnt += stk.back().y;
                S -= stk.back().x * stk.back().y;
                stk.pop_back();
            }
            stk.push_back(mp(val, cnt));
            S += val * cnt;
 
            ans += S;
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
