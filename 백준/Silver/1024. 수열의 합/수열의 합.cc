#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    for(int i = k; i <= 100; i++){
        if (i % 2 == 0){
            if (n % 2 != (i / 2) % 2) continue;
            if (i == 2){
                cout << n/2 << ' ' << n/2+1;
                return 0;
            }
            
            int ti = i/2;
            if (n % ti != 0) continue;
            if ((n / ti) % 2 == 0) continue;
            
            int l = (n / ti) / 2 - (i/2) + 1;
            if (l < 0) continue;
            
            for(int j = 0; j < i; j++){
                cout << l+j << ' ';
            }
            return 0;
            
        }
        else{
            if (n % i != 0) continue;
            int tn = n / i;
            if (tn - (i - 1) /2 < 0) continue;
            
            int l = tn - (i-1)/2;
            if (l < 0) continue;
            
            for(int j = 0; j < i; j++){
                cout << l +j<< ' ';
            }
            return 0;
        }
        
    }
    cout << -1;
}