#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int res = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        res ^= x;
    }
    
    if (n == 1 || res != 0) cout << "koosaga";
    else cout << "cubelover";
    
}