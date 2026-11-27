#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

void solve(){

    int n;
    cin >> n;

    vector<int> dp(n+1, -1), dp2(n+1);
    dp[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int a =q.front(); q.pop();

        if (a + 1 <= n){
            if (dp[a+1] == -1){
                dp[a+1] = dp[a] + 1;
                dp2[a+1] = dp2[a] + 1;
                q.push(a+1);
            }
            else if (dp[a+1] == dp[a]+1){
                dp2[a+1] = min(dp2[a+1], dp2[a] + 1);
            }
        }
        
        if (a * 3 <= n){
            if (dp[a*3] == -1){
                dp[a*3] = dp[a] + 1;
                dp2[a*3] = dp2[a] + 3;
                q.push(a*3);
            }
            else if (dp[a*3] == dp[a]+1){
                dp2[a*3] = min(dp2[a*3], dp2[a] + 3);
            }
        }

        if (1ll * a * a <= n){
            if (dp[a*a] == -1){
                dp[a*a] = dp[a] + 1;
                dp2[a*a] = dp2[a] + 5;
                q.push(a*a);
            }
            else if (dp[a*a] == dp[a]+1){
                dp2[a*a] = min(dp2[a*a], dp2[a] + 5);
            }
        }
    }

    cout << dp[n] << ' ' << dp2[n] << '\n';

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}