#include <bits/stdc++.h>
using namespace std;

int n, m;

int GCD(int n, int m){
    if (m==0) return n;
    return GCD(m, n%m);
}

int LCM(int n, int m){
    return n * m / GCD(n, m);
}

int main(){
    cin >> n >> m;
    
    cout << GCD(max(n, m), min(n, m)) << '\n';
    cout << LCM(max(n, m), min(n, m));
    
}