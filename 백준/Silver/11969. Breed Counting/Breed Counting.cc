#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> A(n+1), B(n+1), C(n+1);
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        
        if (x == 1) A[i] = 1;
        else if (x == 2) B[i] = 1;
        else C[i] = 1;
        
        A[i] += A[i-1];
        B[i] += B[i-1];
        C[i] += C[i-1];
    }
    
    while(q--){
        
        int a, b;
        cin >> a >> b;
        
        cout << A[b] - A[a-1] << ' ' << B[b] - B[a-1] << ' ' << C[b] - C[a-1] << '\n';
        
    }
}