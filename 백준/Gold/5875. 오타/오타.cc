#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int n = s.size();
    vector<int> A(n+1);
    
    int ti = n+1, zi = 0;
    int v = 0;
    for (int i = 1; i <= n; i++){
        if (s[i-1] == '(') A[i] = A[i-1] + 1;
        else A[i] = A[i-1] - 1;
        
        v = min(v, A[i]);
        if (A[i] < 0) ti = min(ti, i);
        
        if (A[i] == 0) zi = i;
    }
    
    vector<int> B(n+1), C(n+1);
    B[n] = A[n];
    C[n] = A[n];
    for(int i = n-1; i >= 0; i--){
        B[i] = min(B[i+1], A[i]);
        C[i] = max(C[i+1], A[i]);
    }
    
    if (B[0] == 0){
        if (A[n] != 2) {
            cout << 0;
            return 0;
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++){
            ans += (B[i] >= 2 && s[i-1] == '(');
        }
        
        cout << ans;
    }
    else{
        if (B[0] != -2){
            cout << 0;
            return 0;
        }
        
        int ans = 0;
        for(int i = 1; i <= ti; i++){
            ans += (s[i-1] == ')');
        }
        
        cout << ans;
    }
}