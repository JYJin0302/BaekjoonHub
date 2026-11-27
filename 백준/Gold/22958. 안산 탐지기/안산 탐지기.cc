#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, max_x;
    cin >> n;
    cout << flush;
    
    cout << "? 1 1 " << n << endl;
    cin >> x;
    max_x = x;
    
    int l, r, dist;
    l = 1, r = n, dist = 2;
    
    while(l < r){
        
        int tdist = min(dist, n);
        int a, b, c;
        a = l + dist/2;
        b = tdist;
        c = (r - a) / b + 1;
        
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        cin >> x;
        
        int tr = a + (c - 1) * b;
        int trr = l + (r - l) / tdist * tdist;
        if (x == max_x){
            l += dist/2;
            r = tr;
        }
        else r = trr;
        
        dist *= 2;
    }
    
    cout << "! " << l;
    
}