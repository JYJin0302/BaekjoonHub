#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll a, b, c, d, u;
    cin >> a >> b >> c >> d >> u;
    
    ll ans = 0;
    if (a <= u) ans = 1 + (u-a)/b;
    
    vector<ll> tmp = {c};
    if (d != 1){
        while(tmp.back() < u){
            tmp.push_back(tmp.back()*d);
        }
    }
    
    if (tmp.back() > u) tmp.pop_back();
    
    for (auto  i: tmp){
        if (i < a || (a-i)%b != 0) ans++;
    }
    
    cout << ans;
}