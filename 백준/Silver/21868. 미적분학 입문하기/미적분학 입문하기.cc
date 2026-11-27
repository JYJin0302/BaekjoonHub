#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    
    if (a > b) swap(a, b);
    
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    ll e1, e2;
    cin >> e1 >> e2;
    
    ll x1, x0;
    cin >> x1 >> x0;
    
    ll x;
    cin >> x;
    
    cout << x1 * x + x0 << '\n'; 
    
    x1 = abs(x1);
    if (x1 == 0) cout << "0 0";
    else{
        cout << e1 / gcd(x1, e1) << ' ' << x1 * e2 / gcd(x1, e1);
    }
    
    
}