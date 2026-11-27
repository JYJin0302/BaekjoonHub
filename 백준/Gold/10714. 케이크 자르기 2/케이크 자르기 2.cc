#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> val;
ll dp[2001][2001];

ll solve(ll a, ll b, int phase){
    
    ll na = (a + 1) % n;
    ll nb = (b + n - 1) % n;
    
    if (dp[a][b] != -1) return dp[a][b];
    if (a == (b + 1) % n) return dp[a][b] = 0;
    
    if (phase == 1){
        if (val[a] > val[b]) return dp[a][b] = solve(na, b, 1 - phase);
        else return dp[a][b] = solve(a, nb, 1 - phase);
    }
    
    ll res = max(val[a] + solve(na, b, 1 - phase), val[b] + solve(a, nb, 1 - phase));
    return dp[a][b] = res;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    
    val = vector<ll>(n);
    for(auto& i : val) cin >> i;
    
    if (n == 1) {
        cout << val[0];
        return 0;
    }
    
    ll ans = 0;
    int l = 1, r = n-1;
    for (int i = 0; i < n; i++){
        ans = max(ans, solve(l, r, 1) + val[i]);
        l = (l + 1) % n;
        r = (r + 1) % n;
    }
    
    cout << ans;
}