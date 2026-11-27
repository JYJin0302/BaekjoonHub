#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = {-1, 0, 1 ,0};
int dy[] = {0, 1, 0, -1};
int n, m;

bool inGrid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int G[1010][1010];
int distU[1010][1010];
int distR[1010][1010];
int distD[1010][1010];
int distL[1010][1010];

queue<pair<int, int>> que[36];

void getDist(int dir, int dist[][1010]){

    int cur = 0;
    if (dir == 0){
        for(int i = 1; i <= m; i++){
            que[G[1][i]].push(mp(1, i));
        }
    }
    else if (dir == 1){
        for(int i = 1; i <= n; i++){
            que[G[i][m]].push(mp(i, m));
        }
    }
    else if (dir == 2){
        for(int i = 1; i <= m; i++){
            que[G[n][i]].push(mp(n, i));
        }
    }
    else if (dir == 3){
        for(int i = 1; i <= n; i++){
            que[G[i][1]].push(mp(i, 1));
        }
    }
    else{
        assert(0);
    }

    int val = 0;
    int emptyCnt = 0;
    for(; emptyCnt < 36; cur = (cur+1)%36, val++){
        if (que[cur].empty()) {
            emptyCnt++;
            continue;
        }
        emptyCnt = 0;
        while(!que[cur].empty()){
            auto[a,b] = que[cur].front(); 
            que[cur].pop();

            if (dist[a][b] != -1) continue;
            dist[a][b] = val;
            for(int f = 0 ; f < 4; f++){
                int na = a + dx[f];
                int nb = b + dy[f];
                if(inGrid(na, nb) && dist[na][nb] == -1){
                    int nc = (cur + G[na][nb]) % 36;
                    que[nc].push(mp(na, nb));
                }
            }
        }
    }

    // cout << "RES: \n";
    // for(int i = 1; i <= n; i++){
    //     for(int j =1 ; j <= m; j++){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

int distUR[1010][1010];
int distUL[1010][1010];
int distDR[1010][1010];
int distDL[1010][1010];

void getDist2(int d1[][1010], int d2[][1010], int dist[][1010]){

    vector<array<int, 3>> tmp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            tmp.push_back({d1[i][j] + d2[i][j] - G[i][j], i, j});
        }
    }
    sort(all(tmp));

    int ix = 0;

    int cur = 0;
    int val = 0;
    int emptyCnt = 0;
    for(; emptyCnt < 36; cur = (cur+1)%36, val++){
        while(ix < (int)tmp.size()){
            auto[a,b, c] = tmp[ix];
            if(a == val){
                if (dist[b][c] == -1){
                    que[cur].push(mp(b, c));
                }
                ix++;
            }
            else break;
        }
        if (que[cur].empty()) {
            emptyCnt++;
            continue;
        }
        emptyCnt = 0;
        while(!que[cur].empty()){
            auto[a,b] = que[cur].front(); 
            que[cur].pop();

            if (dist[a][b] != -1) continue;
            dist[a][b] = val;
            for(int f = 0 ; f < 4; f++){
                int na = a + dx[f];
                int nb = b + dy[f];
                if(inGrid(na, nb) && dist[na][nb] == -1){
                    int nc = (cur + G[na][nb]) % 36;
                    que[nc].push(mp(na, nb));
                }
            }
        }
    }

}

void solve() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if (isalpha(c)) G[i][j] = c - 'A' + 10;
            else G[i][j] = c - '0';
        }
    }

    for(int i = 1;  i <= n; i++){
        for(int j = 1; j <= m; j++){
            distU[i][j] = -1;
            distD[i][j] = -1;
            distR[i][j] = -1;
            distL[i][j] = -1;

            distUR[i][j] = -1;
            distUL[i][j] = -1;
            distDR[i][j] = -1;
            distDL[i][j] = -1;
        }
    }

    getDist(0, distU);
    getDist(1, distR);
    getDist(2, distD);
    getDist(3, distL);
    
    getDist2(distU, distR, distUR);
    getDist2(distU, distL, distUL);
    getDist2(distD, distR, distDR);
    getDist2(distD, distL, distDL);

    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ;j++){
            ans = min(ans, distUL[i][j] + distDR[i][j] - G[i][j]);
            ans = min(ans, distUR[i][j] + distDL[i][j] - G[i][j]);
        }
    }
    
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}