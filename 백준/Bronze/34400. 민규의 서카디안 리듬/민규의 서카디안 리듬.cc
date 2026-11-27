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
    x %= 25;

    if (x < 17) cout << "ONLINE\n";
    else cout << "OFFLINE\n";
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