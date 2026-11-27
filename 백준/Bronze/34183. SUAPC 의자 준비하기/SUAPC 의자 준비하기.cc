#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
 
void solve() {
    
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int nd = n * 3- m;
    if (nd <= 0){
        cout << 0 << '\n';
    }
    else{
        cout << nd * a + b << '\n';
    }
    
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
