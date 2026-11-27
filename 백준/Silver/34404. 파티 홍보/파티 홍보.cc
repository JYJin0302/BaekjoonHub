#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve(){
    
    
    int n;
    cin >> n;

    vector<array<ll, 4>> A;
    for(int i =0 ; i < n; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1>> x2 >> y2;
        A.push_back({x1, y1, x2, y2});
    }

    ll a, b;
    cin >> a>> b;

    int ans = 0;
    for(int i = 0; i < n; i++){
        ll mx = A[i][0] + A[i][2];
        ll my = A[i][1] + A[i][3];
        if (my > mx * a + 2 * b) ans++;
    }
    cout << ans << '\n';

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