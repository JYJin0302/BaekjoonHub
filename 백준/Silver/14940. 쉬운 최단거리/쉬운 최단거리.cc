#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair

int n, m;
int A[1010][1010];
int ans[1010][1010];

int dx[] ={-1, 0, 1, 0};
int dy[]= {0 ,1, 0, -1};
bool inGrid(int x, int y){
    return x >= 0 && x < n &&y >= 0 && y < m;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(ans, -1, sizeof(ans));

    cin >> n >> m;
    
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
            if (A[i][j] == 2) {
                q.push(mp(i, j));
                ans[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        
        int a, b;
        tie(a, b)=  q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int na = a +dx[i];
            int nb = b + dy[i];
            
            if (inGrid(na, nb) && A[na][nb] != 0 && ans[na][nb] == -1){
                ans[na][nb] = ans[a][b] + 1;
                q.push(mp(na, nb));
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (A[i][j] == 0) cout << 0 << ' ';
            else cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    
}