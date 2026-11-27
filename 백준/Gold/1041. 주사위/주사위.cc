#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    
    ll n, a, b, c, d, e, f;
    cin >> n >> a >> b >> c >> d >> e >> f;
    
    ll val1 = min({a,b,c,d,e,f});
    ll val2 = min({a+d,d+b,d+e,d+f,a+b,b+f,f+e,e+a,c+e,c+a,c+b,c+f});
    ll val3 = min({a+d+e, a+b+d, d+b+f, d+e+f, a+c+e, a+b+c, c+b+f, c+e+f});
    
    
    if(n == 1) cout << a+b+c+d+e+f - max({a,b,c,d,e,f});
    else{
        ll ans = (n-2)*(n-2)*val1 + (n-1)*(n-2)*4*val1;
        ans += (n-2)*4*val2 + (n-1)*4*val2;
        ans += 4*val3;
        cout << ans;
    }
}