#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    while(cin >> n){
        
        ll ans = 1, pv = 1;
        while(pv % n != 0){
            pv = (pv * 10 + 1) % n;
            ans++;
        }
        cout << ans << '\n';
    }
}