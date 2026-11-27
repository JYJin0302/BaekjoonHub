#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int v = 1, cnt = 1, ans = 0;
    while(v <= n){
        if (v *10 > n){
            ans += (n - v + 1) * cnt;
            break;
        }
        ans += v*9 * cnt;
        cnt++;
        v *= 10;
    }
    cout << ans;
    
}