#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;
ll A[2501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    
    A[0] = 1;
    A[1] = 1;
    for (int i = 2; i <= 2500; i++){
        A[i] = A[i-1];
        for(int j = 1; j < i; j++){
            A[i] += A[i-j] * A[j-1] % mod;
            A[i] %= mod;
        }
    }
    
    while(t--){
        
        int n;
        cin >> n;
        
        if (n % 2==1 ) cout << "0\n";
        else{
            n /= 2;
            cout << A[n] << '\n';
        }
    }
}