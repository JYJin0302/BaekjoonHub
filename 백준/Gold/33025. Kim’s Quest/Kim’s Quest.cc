#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 998244353;

void solve(){
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A){
        cin >> i;
        i %= 2;
    }

    ll ans = 0;
    vector<ll> dp(5); // E E E
    for(auto f: A){

        if(f == 1) continue;
        dp[2] = (dp[2] * 2 + dp[1]) % mod;
        dp[1] = (dp[1] + dp[0]) % mod;
        dp[0]++;
    }
    ans += dp[2];

    dp = vector<ll>(5); // O O E O O
    for(auto f: A){

        if(f == 1) {
            dp[4] = (dp[4] + dp[3]) % mod;
            dp[3] = (dp[3] + dp[2]) % mod;
            dp[1] = (dp[1] + dp[0]) % mod;
            dp[0]++;
        }
        else{
            dp[2] = (dp[2] + dp[1] + dp[4]) % mod;
        }
    }
    ans = (ans + dp[2] + dp[3] + dp[4]) % mod;

    dp = vector<ll>(5); // E O O E O
    for(auto f: A){
        if(f == 1) {
            dp[2] = (dp[2] + dp[1] + dp[4]) % mod;
            dp[4] = (dp[4] + dp[3]) % mod;
            dp[1] = (dp[1] + dp[0]) % mod;
        }
        else{
            dp[3] = (dp[3] + dp[2]) % mod;
            dp[0]++;
        }
    }
    ans = (ans + dp[2] + dp[3] + dp[4]) % mod;

    dp = vector<ll>(5); // O E O O E
    for(auto f: A){
        if(f == 1) {
            dp[3] = (dp[3] + dp[2]) % mod;
            dp[2] = (dp[2] + dp[1] + dp[4]) % mod;
            dp[0]++;
        }
        else{
            dp[4] = (dp[4] + dp[3]) % mod;
            dp[1] = (dp[1] + dp[0]) % mod;
        }
    }
    ans = (ans + dp[2] + dp[3] + dp[4]) % mod;

    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}