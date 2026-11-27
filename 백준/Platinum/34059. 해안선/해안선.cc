#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
ll F[1001010];
ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1){
            res = res * b % mod;
        }
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

ll nCr(int n, int r){
    ll res = F[n];
    res = res * fastPow(F[r], mod-2) % mod;
    res = res * fastPow(F[n-r], mod-2) % mod;
    return res;
}

void solve() { 
    
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    F[0] = 1;
    for(int i =1; i <= n ;i++) F[i] = F[i-1] * i % mod;

    if (a> b) swap(a, b);

    if (b == a + 1){
        ll ans = fastPow(2, n-3);
        
        int cntR = a - 2;
        int cntL = n - b;

        ans = (ans + nCr(cntR + cntL, cntL)) % mod;
        cout << ans << '\n';
    }   
    else{

        int cntR = a - 2;
        int cntL = n - b;

        ll ans = 1;
        ans = nCr(cntR + cntL, cntL);
        ans = ans * 2 % mod;
        ans = ans * fastPow(2, n - 2 - cntL - cntR - 2) % mod;
        cout << ans << '\n';
    }
    

    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
