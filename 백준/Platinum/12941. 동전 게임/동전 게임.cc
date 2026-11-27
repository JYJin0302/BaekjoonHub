#include <bits/stdc++.h>
using namespace std;

int n, k;
map<int, int> v;
int b[] = {0, 1, 0, 1, 2};
int b1[] = {0, 1, 2, 0, 1};

int solve(int x){
    
    if (k % 2 == 0){
        if (x <= 4) return b1[x];
        
        if (x % 2 == 1) return 0;
        return 1;
    }
    
    if (x <= 4) return b[x];
    if (x % 2 == 1) return 0;
    if (v[x] != 0) return v[x];
    
    if (solve(x/2) == 0)  return v[x] = 1;
    return v[x] = 3 - solve(x/2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int r = 0;
    while(n--){
        
        int x;
        cin >> x;
        
        r ^= solve(x);
    }
    
    if (r == 0) cout << "Nicky";
    else cout << "Kevin";
}