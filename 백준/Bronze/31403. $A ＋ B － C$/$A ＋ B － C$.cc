#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() { 
    
    
    int a, b, c;
    cin >> a>> b >> c;

    int ans1 = a + b - c;

    int sn = to_string(b).size();
    int ans2 = a * pow(10, sn) + b - c;

    cout << ans1 << ' '<< ans2 << '\n';
    

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
