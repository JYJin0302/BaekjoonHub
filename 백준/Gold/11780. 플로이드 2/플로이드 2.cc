#include <bits/stdc++.h>
using namespace std;

int n, m;
const int INF = 1000000000;
int dist[101][101];
int f[101][101];
vector<int> route[101][101];

void get_route(int s, int d){
    if (!route[s][d].empty()) return;
    if (s == d) return;
    if (dist[s][d] == INF) return;
    
    vector<int> temp;
    temp.push_back(s);
    for (int i = 1; i <= n; i++){
        if (i == s) continue;
        
        if (f[s][i] + dist[i][d] == dist[s][d]){
            get_route(i, d);
                
            if (!route[i][d].empty())for (auto k : route[i][d]) temp.push_back(k);
            break;
        }
    }
    
    route[s][d] = temp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <=n;j++) 
        dist[i][j] = INF;
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++) f[i][j] = dist[i][j];
    }
    
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            get_route(i, j);
            if (i == j || dist[i][j] == INF) {
                cout << "0\n";
                continue;
            }
            
            cout << route[i][j].size() + 1 << ' ';
            for(auto k: route[i][j]) cout << k << ' ';
            cout << j << '\n';
            
        }
    }
    
}