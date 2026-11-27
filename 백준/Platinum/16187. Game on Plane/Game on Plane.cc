#include <bits/stdc++.h>
using namespace std;

int n;
int G[205];

int solve(int x){
    
    if (G[x] != -1) return G[x];
    
    if (x <= 1) return G[x] = 0;
    
    vector<bool> isIn(10);
    for(int i = 0; i <= x - i - 2; i++){
        isIn[solve(i) ^ solve(x - i - 2)] = 1;
    }
    
    int i = 0;
    while(isIn[i]) i++;
    
    return G[x] = i;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(G, -1, sizeof(G));
    for(int i = 1 ; i <= 204; i++) solve(i);
    
    int t;
    cin >> t;
    while(t--){
        
        int x;
        cin >> x;
        
        if (x > 204) x = (x%102) + 102;
        
        if (G[x] != 0) cout << "First\n";
        else cout << "Second\n";
    }
    
}