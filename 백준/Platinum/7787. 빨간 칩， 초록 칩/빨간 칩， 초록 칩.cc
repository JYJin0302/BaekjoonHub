#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a>> b;
    
    int cnta = 0, cntb = 0;
    while(a % 2== 0){
        cnta++;
        a /= 2;
    }
    while(b % 2 == 0){
        cntb++;
        b /= 2;
    }
    if (cnta^cntb) cout << "A player wins";
    else cout << "B player wins";
}