#include <bits/stdc++.h>
using namespace std;

int grid[505][505];

int main(){
    
    int n, m;
    cin >> n >> m;
    
    int tot = 0;
    for(int i= 0; i < n; i++){
        for(int j = 0; j < m; j++){
            string s;
            cin >> s;
            
            int cnt = 0;
            for(char c : s) cnt += (c == '9');
            grid[i][j] = cnt;
            tot += cnt;
        }
    }
    
    int maxn = 0;
    for(int i = 0; i < n; i++) {
        int rcnt = 0;
        for(int j = 0; j < m; j++){
            rcnt += grid[i][j];
        }
        maxn = max(maxn, rcnt);
    }
    
    for(int i = 0; i < m; i++){
        int ccnt = 0;
        for(int j = 0; j < n; j++){
            ccnt += grid[j][i];
        }
        maxn = max(maxn, ccnt);
    }
    
    cout << tot - maxn;
    
}