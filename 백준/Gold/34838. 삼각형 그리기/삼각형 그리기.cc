#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    ll n;
    cin >> n;

    ll ans = (n-1) * (n-2) / 2;

    if (n % 3 == 0) cout << (ans - 1) / 3 + 1;
    else cout << ans / 3 << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}