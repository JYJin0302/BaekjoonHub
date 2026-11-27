#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> fib;

ll solve(ll x){
    int s = fib.size() - 1;
    
    while(s >= 0 && fib[s] > x) s--;
    
    if (x == fib[s]) return x;
    return solve(x - fib[s]);
}

int main(){
    
    ll n;
    cin >> n;
    
    ll a = 1, b = 1, t = 0;
    
    while(a <= n){
        t = a+b;
        a = b;
        b = t;
        fib.push_back(a);
    }
    
    cout << solve(n);
}