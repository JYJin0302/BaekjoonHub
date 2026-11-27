#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        int s, k;
        cin >> s >> k;
        
        if (k % 2 == 1){
            if (s % 2 == 1) cout << "1\n";
            else cout << "0\n";
        }
        else{
            if (s % (k+1) == k) cout << k << '\n';
            else if ((s % (k+1)) % 2 == 0) cout << "0\n";
            else cout << "1\n";
        }
    }
    
}