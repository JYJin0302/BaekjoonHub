#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll x){
    // 0^1^2^ ... ^x
    if (x % 4 == 0) return x;
    if (x % 4 == 3) return 0;
    if (x % 4 == 2) return x+1;
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >>n;
    
    ll r = 0;
    while(n--){
        ll x, m;
        cin >> x >> m;
        
        r ^= solve(x + m - 1) ^ solve(x-1);
    }
    if(r) cout << "koosaga";
    else cout << "cubelover";
}