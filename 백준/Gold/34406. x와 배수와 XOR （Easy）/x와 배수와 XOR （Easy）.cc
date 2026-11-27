#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve(){
    
    int x;
    cin >> x;

    if (x == 0){
        cout << 1 << '\n' << 2 << '\n';
        return;
    }
    int ans = (1 << 30);
    cout << 2 << '\n' << ans << ' '<< ans+ 1 << '\n'; 
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}