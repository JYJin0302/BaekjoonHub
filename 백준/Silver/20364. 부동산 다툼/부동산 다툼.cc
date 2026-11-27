#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    
    vector<bool> v(n+1);
    while(q--){
        
        int x;
        cin >> x;
        
        int tx = x;
        int res = 0;
        while(tx){
            if (v[tx]) res = tx;
            tx /= 2;
        }
        
        if (res == 0) v[x] = 1;
        cout << res << '\n';
    }
}