#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


const int INF = 1e8;

int tcnt = 0;
void solve(){
    
    ll L, n;
    cin >> L >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    vector<int> dp(10101, INF);
    dp[0] = 0;
    for(int i = 1; i <= 10000; i++){
        for(auto f : A) if (i >= f){
            dp[i] = min(dp[i], dp[i-f] + 1);
        }
    }

    int mx = *max_element(all(A));

    int cnt = 0, loop = -1;
    for(int i = mx; i <= 10000; i++){
        if (dp[i] == INF || dp[i] == dp[i-mx] + 1){
            cnt++;
        }
        else cnt = 0;
        if (cnt == mx){
            loop = i;
            break;
        }
    }
    
    ll ans = -1;
    if (L <= 10000){
        if (dp[L] != INF) ans = dp[L];

    }
    else{
        for(int i = 0; i < mx; i++){
            int test = loop - i;
            if(test % mx == L % mx){
                if (dp[test] == INF) ans = -1;
                else ans = dp[test] + (L - test) / mx;
                break;
            }
        }
    }
    cout << "Case #" << ++tcnt << ": ";
    if (ans == -1) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}