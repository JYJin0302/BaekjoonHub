#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int x, y, z;
        cin >> x >> y >> z;
        
        int cnt = 0;
        cnt = x%2 + y%2 + z%2;
        
        if (cnt == 0 || cnt == 1) cout << "R\n";
        else cout << "B\n";
    }
}