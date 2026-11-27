#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    bool ok = 1;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++){
        int x = A[i];
        int nl = x - r, nr = x - l;
        
        if (nr < 0) ok = 0;
        if (nl < 0) nl = (nl%3 + 3) % 3;
        
        int xl = 0, xr = 0;
        if (nl % 2 == 0) xl = nl/2;
        else xl = nl/2 + 2;
        xr = nr*2;
        
        l = xl, r = xr;
    }
    
    if(ok && l == 0) cout << "YES";
    else cout << "NO";
}