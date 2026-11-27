#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000003;

ll fastP(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex % 2 == 1) res *= b;
        b = b*b % mod;
        res %= mod;
        ex >>= 1;
    }
    return res;
}

int main(){
    
    ll k;
    cin >> k;
    
    ll a = fastP(2, 2*k - 4);
    ll b = a*2 % mod;
    
    ll ta = fastP(2, k-1);
    ta = fastP(ta, mod -2);
    ta = (-ta + mod + 2) % mod;
    ta = ta*ta % mod;
    a = a*ta % mod;
    
    ll tb = fastP(4, k);
    tb = (1 - fastP(tb, mod-2) + mod) % mod;
    tb = tb*2 % mod;
    tb = tb * (fastP(3, mod-2)) % mod;
    b = b * tb % mod;
    
    cout << (a - b + mod) % mod;
}