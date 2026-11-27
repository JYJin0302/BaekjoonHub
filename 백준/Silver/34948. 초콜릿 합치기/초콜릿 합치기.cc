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

    vector<pair<ll, ll>> A(n);
    for(auto& i : A) cin >> i.x;
    for(auto& i : A) cin >> i.y;
    sort(all(A));

    ll ans = 0;
    ll s = 0;
    for(int i = n-1; i >= 0; i--){
        s += A[i].y;
        ans = max(ans, A[i].x * s);
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