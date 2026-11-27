#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    ll A[1000001], B[1000001];
    
    for (int i = 1; i <= 1000000; i++){
        for (int j = i; j <= 1000000; j += i){
            A[j] += i;
        }
    }
    
    for (int i = 1; i <= 1000000; i++) B[i] = B[i-1] + A[i];
        
    
    ll n;
    cin >> n;
    
    while(n--){
        ll x;
        cin >> x;
        cout << B[x] << '\n';
    }
}