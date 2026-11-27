#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        ll target = b - a;
        if (target <= 3) cout << target << '\n';
        else{
            ll temp = sqrt(target);
            if (target == temp*temp) cout << 2*temp - 1 << '\n';
            else if (target <= temp*(temp+1)) cout << 2*temp << '\n';
            else cout << 2*temp +1 << '\n';
        }
        
    }    
}