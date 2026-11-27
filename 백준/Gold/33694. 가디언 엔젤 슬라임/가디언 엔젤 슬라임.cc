#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
void solve() {
 
    ll n, x;
    cin >> n >> x;
 
    map<ll, int> dp;
 
    for(int i = 0; i <  n;i++){
        ll a, b, c, t;
        cin >> a>> b>> c>> t;
 
        ll L = -1, R = -1;
        ll maxH = 0;
        ll T = 0;
        
        ll d1 = (x + a - 1) / a;
        ll d2 = (c + a - 1) / a;
        if (d1 <= d2) L = d1;
        else continue;
        maxH = d2 * a;
 
        R = d2 + (maxH - x) / b + 1;
        
        // t + L ~ t + R
        dp[t + L]++;
        dp[t + R]--;
    }
 
    ll preX = 0, val = 0;
    ll ans = 0;
    for(auto [a,b] : dp){
        ll nval = val + b;
        if (nval >= 3 && val < 3){
            preX = a;
        }
        else if (val >= 3 && nval < 3){
            ans += a - preX;
        }
 
        val = nval;
    }
    cout << ans << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
