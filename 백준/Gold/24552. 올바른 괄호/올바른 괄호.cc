#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    vector<int> A(n+1);
    for (int i =1 ; i <= n; i++){
        A[i] = A[i-1] + (s[i-1] == '(')*2 - 1;
    }
    
    vector<int> B(n+1);
    B[n] = A[n];
    for(int i = n-1; i >= 0; i--) {
        B[i] = min(B[i+1], A[i]);
    }
    
    int ans = 0;
    if (A[n] == 1){
        for(int i = 1; i <= n; i++){
            if (B[i] >= 1 && s[i-1] == '(') ans++;
        }
    }
    else{
        int v = 0;
        for(int i = 1; i <= n; i++){
            v = min(v, A[i]);
            if (s[i-1] == ')') ans++;
            if (v < 0) break;
        }
    }
    cout << ans;
}