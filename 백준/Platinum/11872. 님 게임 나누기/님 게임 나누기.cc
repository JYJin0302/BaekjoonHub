#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int res = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x % 4 == 3) res ^= x + 1;
        else if (x % 4 == 0) res ^= x-1;
        else res ^= x;
    }
    
    if (res != 0) cout << "koosaga";
    else cout << "cubelover";
}