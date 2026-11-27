#include <bits/stdc++.h>
using namespace std;

int n, a, b;
void solve(){
    
    if (a + b > n+1) {
        cout << -1;
        return;
    }
    
    if (a == 1){
        cout << b << ' ';
        for (int i = 0; i < n-b; i++) cout << 1 << ' ';
        for(int i = b-1; i >= 1; i--) cout << i << ' ';
        return;
    }
    
    for (int i = 0; i < n+1-a-b; i++) cout << 1 << ' ';
    for (int i = 1; i < a; i++) cout << i << ' ';
    cout << max(a, b) << ' ';
    for (int i = b-1; i >= 1; i--) cout << i << ' ';
}

int main(){
    
    cin >> n >> a >> b;
    solve();
}