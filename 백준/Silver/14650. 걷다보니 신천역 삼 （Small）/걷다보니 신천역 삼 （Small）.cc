#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin >> n;
    
    if (n == 1) cout << 0;
    else{
        int ans = 2;
        n -= 2;
        while(n--) ans *= 3;
        cout << ans;
    }
}