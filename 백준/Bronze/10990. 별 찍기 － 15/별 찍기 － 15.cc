#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        string b1(n - i, ' ');
        if (i == 1) cout << b1 + '*' << '\n';
        else{
            string b2(2*i -3, ' ');
            cout << b1 << '*' << b2 << '*' << '\n';
        }
    }
    
}
