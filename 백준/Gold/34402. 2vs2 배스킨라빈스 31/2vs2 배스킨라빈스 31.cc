#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve(){
    
    ll n, k;
    cin >> n >> k;

    n--;

    vector<pair<int, int>> ans;
    // 1 3 , 2 4
    if (n % (k+1) == 0) ans.push_back(mp(2, 4));
    else ans.push_back(mp(1, 3));

    // 1 2, 3 4
    if (n % (2 * k + 2) <= 1) ans.push_back(mp(3, 4));
    else ans.push_back(mp(1, 2));

    // 1 4, 2 3
    ll m = n % (2 * k + 2);
    if (m >= 1 && m <= k+1) ans.push_back(mp(1, 4));
    else ans.push_back(mp(2, 3));

    sort(all(ans));
    for(auto[a,b] : ans) cout << "(" << a << ',' <<b<< ") ";
    cout << '\n';
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