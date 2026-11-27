#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int l, r;
    cin >> l >> r;

    int mx = max(l, (r+1)/2);

    cout << mx << ' ';
    int p = 0;
    for(int i = r; i >= l; i--){
        if (i == mx) continue;
        if (!p) cout << '-';
        cout << i << ' ';
        p ^= 1;
    }
    cout << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}