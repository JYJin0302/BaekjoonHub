#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int a,b,c,d;
    cin >> a>>b>>c>>d;
    
    int ans;
    if (a+b == 0) ans = d + min(1, c);
    else if (b == 0) ans = a;
    else ans = a + d + min(b, c+1) + min(b, c);
    
    cout << ans;
}