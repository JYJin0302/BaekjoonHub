#include <bits/stdc++.h>
using namespace std;

int A[101];

int main(){
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n;i ++) cin >> A[i];
    
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        
        if(a == 1){
            for (int i = b; i <= n; i+=b) A[i] = 1 - A[i];
        }
        else{
            int l = b - 1, r = b + 1;
            while(l >= 1 && r <= n){
                if (A[l] != A[r]) break;
                l--, r++;
            }
            
            for (int i = l + 1; i < r; i++) A[i] = 1 - A[i];
        }
    }
    
    for (int i = 1; i <=n ;i++) {
        cout << A[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }
    
}