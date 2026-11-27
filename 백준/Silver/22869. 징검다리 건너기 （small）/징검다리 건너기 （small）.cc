#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    vector<bool> B(n);
    B[0] = 1;
    
    for(int i = 1; i < n; i++){
        bool ok = 0;
        for (int j = 0; j < i; j++){
            ok |= (B[j] && (i - j) * (1 + abs(A[i] - A[j])) <= k);
        }
        B[i] = ok;
    }
    
    if (B[n-1]) cout << "YES";
    else cout << "NO";
}