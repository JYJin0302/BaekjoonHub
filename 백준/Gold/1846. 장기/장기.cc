#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    if (n == 3) cout << -1;
    else if (n % 2 == 0) {
        for (int i = 1; i < n/2; i++) cout << i+1 << '\n';
        cout << 1 << '\n';
        for (int i = 1; i < n/2; i++) cout << n/2 + 1 + i << '\n';
        cout << n/2 + 1;
    }
    else{
        cout << n/2+1 << '\n';
        for (int i = 1; i <= n/2; i++) cout << i << '\n';
        for(int i =1 ; i < n/2; i++) cout << n/2 + 2 + i << '\n';
        cout << n/2+2;
    }
}