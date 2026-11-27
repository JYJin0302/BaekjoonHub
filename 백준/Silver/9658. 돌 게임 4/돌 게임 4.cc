#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<bool> A(n+1);
    A[0] = 1;
    for (int i = 1; i <= n; i++){
        bool ok = 0;
        if (i - 1 >= 0) ok |= !A[i-1];
        if (i - 3 >= 0) ok |= !A[i-3];
        if (i - 4 >= 0) ok |= !A[i-4];
        A[i] = ok;
    }
    
    if (A[n]) cout << "SK";
    else cout << "CY";
}