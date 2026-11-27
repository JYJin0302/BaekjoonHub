#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll grundy(ll x){
    if (x <= 3) return 0;
    if (x <= 15) return 1;
    if (x <= 81) return 2;
    if (x <= 6723) return 0;
    if (x <= 50625) return 3;
    if (x <= 2562890624) return 1;
    return 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    ll res = 0;
    while(n--){
        ll x;
        cin >> x;
        res ^= grundy(x);
    }
    
    if (res != 0) cout << "koosaga";
    else cout << "cubelover";
}
