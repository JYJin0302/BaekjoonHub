#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int v = 0, ans = 0;
    for(int i = 0; i < 4; i++){
        int a, b;
        cin >> a >> b;
        v += b - a;
        ans = max(ans, v);
    }
    cout << ans;
}