#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n;
    cin >> n;
    
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
        while(ans%10 == 0) ans /= 10;
        ans %= (ll)1e12;
    }
    ans %= 100000;
    
    string s = to_string(ans);
    string t(5-s.size(), '0');
    cout <<t  << s;
}