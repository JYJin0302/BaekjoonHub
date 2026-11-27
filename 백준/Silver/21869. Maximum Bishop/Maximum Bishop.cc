#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    if (n == 1){
        cout << "1\n1 1";
        return 0;
    }
    
    cout << n*2-2 << '\n';
    for (int i = 0; i < n; i++){
        cout << "1 " << i+1 << '\n';
    }
    
    for (int i = 1; i < n-1; i++){
        cout << n << ' ' << i+1 << '\n';
    }
}