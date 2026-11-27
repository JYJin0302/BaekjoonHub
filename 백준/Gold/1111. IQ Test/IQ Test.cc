#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n;
    cin >> n;
    
    vector<ll> Num(n);
    for (auto& i : Num) cin >> i;
    
    if (n == 1){
        cout << 'A';
        return 0;
    }
    if (n == 2){
        if (Num[0] == Num[1]) cout << Num[0];
        else cout << 'A';
        return 0;
    }
    
    ll a, b, c;
    a = Num[0], b = Num[1], c = Num[2];
    
    ll d1 = b - a, d2 = c - b;
    
    if ((d1 == 0 && d2 != 0) || (d1 != 0 && d2 % d1 != 0)){
        cout << 'B';
        return 0;
    }
    
    if (d1 == 0 && d2 == 0) {
        for (int i = 2; i < n; i++) if (Num[i] != a){
            cout << 'B';
            return 0;
        }
        cout << a;
        return 0;
    }
    
    ll A = d2 / d1;
    ll B = b - a*A;
    
    for (int i = 2; i < n; i++){
        if (Num[i] != Num[i-1]*A + B) {
            cout << 'B';
            return 0;
        }
    }
    
    cout << Num[n-1] * A + B;
}