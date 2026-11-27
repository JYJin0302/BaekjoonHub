#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n, k;
    cin >> n >> k;
    cout << setprecision(10);
    
    vector<ll> A(n+1), B(n+1);
    for (int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        
        A[i] = x;
        B[i] = x * x;
        
        if (i != 0){
            A[i] += A[i-1];
            B[i] += B[i-1];
        }
    }
    
    long double ans = 100000000;
    
    for (int i = 1; i <= n; i++){
        for (int j = i + k - 1; j <= n; j++){
            
            long double len = j - i + 1;
            long double m = (A[j] - A[i-1])/ len;
            long double tans = sqrt((B[j] - B[i-1] - 2*m*(A[j] - A[i-1]) + len * m*m)/ len);
            
            ans = min(ans, tans);
        }
    }
    
    cout << ans;
    
}