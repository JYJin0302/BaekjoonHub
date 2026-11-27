#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> fibo(1000000);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= abs(n); i ++){
        fibo[i] = (fibo[i-1] + fibo[i-2])%1000000000;
    }
    
    if (n < 0 && abs(n)%2^1) cout << -1 << endl;
    else if (n==0) cout << 0 << endl;
    else cout << 1 << endl;
    cout << fibo[abs(n)];
    
    
    
}