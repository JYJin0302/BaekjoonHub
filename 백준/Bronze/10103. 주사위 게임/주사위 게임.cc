#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int v1 = 100, v2 = 100;
    
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        if (a > b) v2 -= a;
        if (b > a) v1 -= b;
    }
    cout << v1 << ' ' << v2;
}