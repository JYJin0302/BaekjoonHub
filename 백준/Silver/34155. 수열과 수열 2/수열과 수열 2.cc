#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 998244353;

void solve() {
    
    int n;
    cin >> n;
    
    ll ans = 1;
    for(int i =1 ; i <= n ;i++){
        int x;
        cin >> x;
        if (x == i) ans = ans * (n-1) % mod;
        else ans = ans * (n - 2) % mod;
    }
    cout << ans << '\n';
    

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}