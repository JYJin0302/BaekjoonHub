#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){

        int a, b;
        cin >> a >> b;
        
        while(a != 1){
            int tx = b / a + 1;
            
            a = tx*a - b;
            b = tx*b;
            
            int gd = gcd(a, b);
            a /= gd, b /= gd;
        }
    
        cout << b << '\n';
    }
}