#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll t = n % 7;
    if (t == 0 || t == 2){
        cout << "CY";
    }
    else cout << "SK";
    
}