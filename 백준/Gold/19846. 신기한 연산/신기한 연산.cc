#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m, q;
    cin >> n >> m >> q;
    
    while(q--){
        int a, b;
        cin >> a >> b;
    }
    
    string s;
    for (int i = 0; i < n; i++){
        s += 'a' + i;
        s += 'a' + i;
    }
    
    int len = 0;
    while(len < m){
        int x = min(m - len, n*2);
        cout << s.substr(0, x);
        len+= x;
    }
}