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
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    vector<int> mx(n);
    for(int i= n-1; i>= 0; i--){
        mx[i] = A[i];
        if (i != n-1) mx[i] = max(mx[i], mx[i+1]);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += mx[i] - A[i];
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