#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for (int i= 0; i < n; i++){
        bool ok = 1;
        for (int j = 1; j <= 10; j++){
            int x;
            cin >> x;
            
            if (x != (j - 1) % 5 + 1) ok = 0;
        }
        
        if (ok) cout << i+1 << '\n';
    }
    
    
    
    
}