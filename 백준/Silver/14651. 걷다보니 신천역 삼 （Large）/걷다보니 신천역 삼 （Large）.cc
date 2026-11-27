#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n;
    cin >> n;
    
    const ll mod = 1e9 + 9;
    
    if (n == 1) cout << 0;
    else{
        ll ans = 2;
        n -= 2;
        while(n--) {
            ans *= 3;
            ans %= mod;
        }
        cout << ans;
    }
}