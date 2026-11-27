#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int p;
    cin >> p;
    
    for(int i= 1; i < n; i++){
        int x;
        cin >> x;
        p ^= x;
    }
    
    if (p != 0) cout << "koosaga";
    else cout << "cubelover";
    
}