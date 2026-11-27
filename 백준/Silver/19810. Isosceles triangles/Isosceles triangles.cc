#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    ll n;
    cin >> n;

    ll ans = (n-1) / 2 * n;
    if (n % 3 == 0){
        ans -= 2 * (n / 3);
    }
    cout << ans << '\n';

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
