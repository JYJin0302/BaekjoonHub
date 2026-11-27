#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()

void solve(){

    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    sort(all(A));
    reverse(all(A));

    int tot = 0;
    for(auto f : A) tot += f;

    tot >>= 1;

    vector<ll> dp(tot+1);
    dp[0] = 1;
    ll ans = 0;
    for(auto f : A){
        vector<ll> ndp(tot+1);
        for(int i = 0; i <= tot; i++){
            ndp[i] += dp[i];
            if (i + f > tot){
                ans += dp[i];
            }
            else ndp[i+f] += dp[i];
        }
        dp = ndp;
    }
    cout << ans << '\n';
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}