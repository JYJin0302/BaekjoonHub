#include <bits/stdc++.h>
using namespace std;

string s;

bool isPal(int l, int r){
    int nl = l, nr = r;
    if (r - l <= 1) return 1;
    while(nl <= nr){
        if (s[nl] != s[nr]) return 0;
        nl++;
        nr--;
    }
    
    return isPal((l+r)/2 + 1, r);
}

int main(){
    cin >> s;
    
    int n = s.size();
    int new_n = n/2;
    if (isPal(0, n-1)) cout << "AKARAKA";
    else cout << "IPSELENTI";
    
}
