#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);;
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n*m; i++){
        int x;
        cin >> x;
    }
    
    int x, y;
    x = 0, y = 0;
    
    cout << (n+m-2 + (n+m)%2)*2 << '\n';
    if ((n+m)% 2 == 0){
        cout << "0 0\n1 1\n0 0\n1 1\n";
        if (n == 2) x = 1, y = 2;
        else x = 2, y = 1;
    }
    
    while(x < n -1){
        if (x + 1 == n-1){
            cout << x << ' ' << y << '\n';
            cout << x+1 << ' ' << y << '\n';
            cout << x << ' ' << y << '\n'; 
            cout << x+1 << ' ' << y << '\n';
            
            x++,y++;
            break;
        }
        cout << x << ' ' << y << '\n';
        cout << x+1 << ' ' << y << '\n';
        cout << x << ' ' << y << '\n';
        cout << x+1 << ' ' << y << '\n';
        x += 2;
    }
    
    while(y < m-1){
        cout << x << ' ' << y << '\n';
        cout << x << ' ' << y +1 << '\n';
        cout << x << ' ' << y << '\n';
        cout << x << ' ' << y +1 << '\n';
        y += 2;
    }
    
}