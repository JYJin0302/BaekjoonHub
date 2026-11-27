#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int res = 0;
    while(n--){
        int x;
        cin >> x;
        
        if (x % 2 == 0) res ^= (x/2) - 1;
        else res ^= x/2 + 1;
    }
    
    if (res != 0) cout << "koosaga";
    else cout << "cubelover";
    
}