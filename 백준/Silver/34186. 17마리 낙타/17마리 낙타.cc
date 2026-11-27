#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
#define NO {cout << -1 << '\n'; return;}
 
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
 
void solve() {
    
    ll n, a, b, c;
    cin >> n >> a>> b>> c;
 
    ll num = 0, den = 1;
    for(auto v : {a, b, c}){
        // add 1 / v
        ll num2, den2;
        den2 = den * v;
        num2 = num * v + den;
 
        ll g = gcd(den, v);
 
        num = num2 / g;
        den = den2 / g;
    }
 
    if (num > den) NO;
 
   // cout << num << ' '<< den << '\n';
 
    if (n % num == 0){
        ll mul = n / num;
        num *= mul;
        den *= mul;
    }
 
    if (num == n){
        cout << den - n << '\n';
    }
    else NO;
 
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
