#include <bits/stdc++.h>
using namespace std;

int t[101][101];

bool solve(int n, int m){
    
    if (n > m) swap(n, m);
    if (t[n][m] != 0) return t[n][m] > 0;
    if (n == 1 && m == 1) return 0;
    
    bool ok = 0;
    // select n
    for (int i = 1; i*2 <= m; i++){
        if (!solve(i, m-i)) ok = 1;
    }
    // select m
    for (int i = 1; i*2 <= n; i++){
        if (!solve(i, n-i)) ok = 1;
    }
    
    if (ok) t[n][m] = 1;
    else t[n][m] = -1;
    return ok;
}

int main(){
    
    int n, m;
    cin >> n >> m;
    if (solve(n, m)) cout << 'A';
    else cout << 'B';
}