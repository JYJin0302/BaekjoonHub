#include <bits/stdc++.h>
using namespace std;

int GCD(int n, int r){
    if (r == 0) return n;
    return GCD(r, n%r);
}

int LCM(int n, int r){
    return r * n / GCD(n, r);
}


int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << LCM(max(a, b), min(a, b)) << '\n';
    }
}