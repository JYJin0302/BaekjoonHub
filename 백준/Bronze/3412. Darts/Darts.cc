#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
    int n;
    cin >> n;
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        
        for(ll j = 1; j <= 10; j++){
            if (a*a+ b*b <= j*j*400){
                ans += 11-j;
                break;
            }
        }
    }
    cout << ans << '\n';
    }
}