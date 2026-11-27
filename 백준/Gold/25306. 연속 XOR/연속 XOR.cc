#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll v){
    
    ll res = 0;
    if (v % 2== 0) res = (v >> 1) << 1;
    
    if (v % 4 == 1 || v % 4 == 2) res ++;
    return res;
}

int main(){
    
    ll a, b;
    cin >> a >> b;
    
    ll ans = solve(b) ^ solve(a-1);
    cout << ans;
}