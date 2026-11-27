#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n;
    cin >> n;
    
    if (n == 1){
        cout << 1 << '\n';
        return;
    }
    if (n & 1){
        cout << -1 << '\n';
        return;
    }

    if (n % 4 == 0){
        cout << -1 << '\n';
        return;
    }

    int tn = n + 2;
    if (__builtin_popcount(tn) != 1){
        cout << -1 << '\n';
        return;
    }
    
    for(int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';

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