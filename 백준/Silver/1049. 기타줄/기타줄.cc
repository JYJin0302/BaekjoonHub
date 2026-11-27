#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    int a = 1000, b = 1000;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a = min(a, x);
        b = min(b, y);
    }
    
    if (a >= b*6) cout << n*b;
    else{
        int v = n/6;
        cout << v*a + min(a, b*(n%6));
    }
    
}