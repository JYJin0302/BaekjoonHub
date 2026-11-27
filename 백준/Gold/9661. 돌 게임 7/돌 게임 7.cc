#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll x;
    cin >> x;
    
    x %= 5;
    
    if (x == 0 || x == 2) cout << "CY";
    else cout << "SK";
}