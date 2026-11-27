#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin >> t;
    while(t--){
        
        int s;
        cin >> s;
        
        int q;
        cin >> q;
        while(q--){
            int a, b;
            cin >> a >> b;
            s += a*b;
        }
        cout << s << '\n';
    }
    
}