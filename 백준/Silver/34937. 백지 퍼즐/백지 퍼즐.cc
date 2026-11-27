#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;


void solve(){
    
    int n, m;
    cin >> n >> m;

    int tot = (n-1) * m + n * (m-1);

    ll ans = 1;
    for(int i =0 ; i <tot; i++){
        ans = ans * 3 % mod;
    }
    cout << ans << '\n';


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}