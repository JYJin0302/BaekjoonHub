#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int w, h, x, y, p;
    cin >> w >> h >> x >> y>> p;
    
    int r = h/2;
    
    int ans = 0;
    while(p--){
        
        int a,b;
        cin >> a >> b;
        
        bool ok = 0;
        ok |= (a >= x && a <= x+w && b >= y && b <= y+h);
        ok |= (a-x)*(a-x)+(b-y-r)*(b-y-r) <= r*r;
        ok |= (a-x-w)*(a-x-w)+(b-y-r)*(b-y-r) <= r*r;
        
        ans += ok;
    }
    cout << ans;
}