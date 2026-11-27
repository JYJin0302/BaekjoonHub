#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n;
    cin >> n;

    vector<ll> A(n);
    for(auto& i : A) {
        cin >> i;
        if (i % 2 == 0) i--;
    }
    sort(all(A));
    
    ll ans = 0;
    for(auto f : A) ans += f;
    if (ans % 2 == 0) ans -= A[0];
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
