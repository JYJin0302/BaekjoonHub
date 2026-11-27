#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll k, a, b, c, d;
    cin >> k >> a >> b>> c>> d;
    
    if (a*k+b == c*k+d) cout << "Yes " << a*k+b;
    else cout << "No";
    
}