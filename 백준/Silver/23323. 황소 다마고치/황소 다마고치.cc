#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
    ll n, m;
    cin >> n >> m;
    
    ll ans = 0;
    while(n > 1) {
        ans++;
        n /= 2;
    }
    
    cout << ans + m + 1 << '\n';;
    }
}