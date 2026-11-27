#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, p, q;
map<ll, ll> val;

void solve(ll x){
    
    if (val[x] != 0) return;
    
    solve(x/p), solve(x/q);
    val[x] = val[x/p] + val[x/q];
}

int main(){
    
    
    cin >> n >> p >> q;
    
    val[0] = 1;
    
    solve(n);
    cout << val[n];
    
}