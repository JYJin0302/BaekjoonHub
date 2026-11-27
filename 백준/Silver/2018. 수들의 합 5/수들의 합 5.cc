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

    int ans = 0;
    for(int i = 1; i <= x; i++){
        if (i & 1){
            if (x % i == 0 && (x / i) - i/2 > 0) ans++;
        }
        else{
            if (x % (i/2) == 0 && x / (i/2) % 2 == 1){
                int mn = x / (i/2) / 2;
                if (mn >= 1 && mn - (i/2) + 1 >= 1){
                    ans++;
                }
            }
        }
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