#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int A[2001][2001];
bool v[2001][2001];

bool inGrid(int x, int y){
return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (A[i][j] == 3){
                q.push({i, j, k});
                v[i][j] = 1;
            }
        }
    }
    while(!q.empty()){
        
        int a, b, c;
        tie(a, b, c) = q.front();
        q.pop();
        
        if (c == 0) continue;
        
        for (int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b  + dy[i];
            
            if (inGrid(na, nb) && !v[na][nb]){
                v[na][nb] = 1;
                A[na][nb] = max(A[na][nb], 3);
                q.push({na, nb, c-1});
            }
        }
    }
    
    memset(v, 0, sizeof(v));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (A[i][j] == 4) q.push({i, j, 0});
        }
    }
    
    while(!q.empty()){
        
        int a, b, c;
        tie(a, b, c) = q.front();
        q.pop();
        
        if (A[a][b] == 2) {
            cout << c;
            return 0;
        }
        
        for(int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && A[na][nb]%2 == 0 && !v[na][nb]){
                v[na][nb] = 1;
                q.push({na, nb, c+1});
            }
                
        }
    }
    cout << -1;
}