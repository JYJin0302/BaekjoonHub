#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main(){
    int n, k, a, b, c;
    cin >> n;
    
    vector<vector<int>> path(n+1, vector<int>(n+1, INF));
    for(int i = 1; i <= n; i++) path[i][i] = 0;
    
    cin >> k;
    while(k--){
        cin >> a >> b >> c;
        path[a][b] = min(path[a][b], c);
    }
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (path[i][j] == INF) path[i][j] = 0;
            cout << path[i][j] << ' ';
        }
        cout << '\n';
    }
    
}