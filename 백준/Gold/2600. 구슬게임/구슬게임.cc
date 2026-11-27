#include <bits/stdc++.h>
using namespace std;

int b1, b2, b3;
int dp[501][501];

bool solve(int x, int y){
    if (x > y) swap(x, y);
    
    if (dp[x][y] != 0) return dp[x][y] > 0;
    if (x == 0 && (y == b1 || y == b2 || y == b3)){
        dp[x][y] = 1;
        return 1;
    }
    
    bool ok = 0;
    if (x >= b1) ok |= !solve(x-b1, y);
    if (x >= b2) ok |= !solve(x-b2, y);
    if (x >= b3) ok |= !solve(x-b3, y);
    if (y >= b1) ok |= !solve(x, y-b1);
    if (y >= b2) ok |= !solve(x, y-b2);
    if (y >= b3) ok |= !solve(x, y-b3);
    
    if (ok) dp[x][y] = 1;
    else dp[x][y] = -1;
    
    return ok;
}

int main(){
    
    cin >> b1 >> b2 >> b3;
    
    for (int i = 0; i < 5; i++){
        int a, b;
        cin >> a >> b;
        
        if (solve(a, b)) cout << "A\n";
        else cout << "B\n";
    }
}