#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k;
    cin >> k;
    
    int c;
    cin >> c;
    
    while(c--){
        
        int a, b;
        cin >> a >> b;
        
        if (a > b){
            a--;
            int l = k - a;
            if (b + l < a) cout << "0\n";
            else cout << "1\n";
        }
        else if (a < b){
            b--;
            int l = k - b - 1;
            if (a + l < b) cout << "0\n";
            else cout << "1\n";
        }
        else cout << "1\n";
    }
}