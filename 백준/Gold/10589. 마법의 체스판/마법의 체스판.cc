#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    cout << n/2 + m/2 << '\n';
    for (int i = 1; i <= n/2; i++){
        cout << i*2 << " 1 " << i*2 << ' ' << m << '\n';
    }
    for (int i = 1; i <= m/2; i++){
        cout << "1 " << i*2 << ' ' << n << ' ' << i*2 << '\n';
    }
    
}