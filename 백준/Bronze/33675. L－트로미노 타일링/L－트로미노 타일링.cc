#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

void solve(){

    int n;
    cin >> n;

    ll ans = 0;
    if (n & 1){}
    else {
        ans = 1ll << (n / 2);
    }
    cout << ans << '\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}