#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int base = 1;
    int diag = 9901;
    
    for (int i = 0; i < 100; i++){
        for (int j = 1; j <= 100; j++){
            int num = i*100 + j;
            if (i + j == 100) cout << diag++ << ' ';
            else cout << base++ << ' ';
        }
        cout << '\n';
    }
    
    
}