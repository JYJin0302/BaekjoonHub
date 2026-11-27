#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n, m;
    cin >> n >> m;
    vector<ll> A(n);
    for(auto& i :A ) cin >> i;
    vector<ll> B(m);
    for(auto& i : B) cin >> i;

    sort(all(A));
    sort(all(B));

    int ix = m-1;
    ll ans = 0;
    for(int i = n-1; i >=0 && ix >= 0; i--){
        if (A[i] < B[ix]) {
            ans += B[ix];
            ix--;
        }
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
