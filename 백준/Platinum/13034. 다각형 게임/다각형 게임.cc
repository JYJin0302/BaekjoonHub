#include <bits/stdc++.h>
using namespace std;

int n;
int G[1001];

int solve(int x){
    
    if (G[x] != -1) return G[x];
    
    if (x <= 1) return G[x] = 0;
    
    vector<bool> isIn(n+1);
    for(int i = 0; i <= x - i - 2; i++){
        isIn[solve(i) ^ solve(x - i - 2)] = 1;
    }
    
    int i = 0;
    while(isIn[i]) i++;
    
    return G[x] = i;
}

int main(){
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) G[i] = -1;
    
    if (solve(n) > 0) cout << 1;
    else cout << 2;
}