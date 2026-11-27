#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m, T;
char G[505][505];
int dx[] = {-1, 0, 1 ,0};
int dy[] = {0, -1, 0, 1};
bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

array<int, 3> nxt[505][505][4];

array<int, 3> getNext(int x, int y, int dir){
    if (!inGrid(x, y)) return {x, y, dir};
    if (nxt[x][y][dir][0] != -1) return nxt[x][y][dir];
    if (G[x][y] != 'T') return nxt[x][y][dir] = {x, y, dir};

    nxt[x][y][dir] = {x, y, dir};
    int nd = (dir + 1) % 4;
    int nx = x + dx[nd];
    int ny = y + dy[nd];
    return nxt[x][y][dir] = getNext(nx, ny, nd);
}

int D[505][505][4];

void solve(){
    
    cin >> n >> m >> T;

    memset(nxt, -1, sizeof nxt);
    memset(D, -1, sizeof D);

    int sx, sy, dir;

    for(int i =0; i < n; i++){
        for(int j =0; j < m; j++){
            cin >> G[i][j];
            if (isdigit(G[i][j])){
                sx = i, sy = j;
                dir = G[i][j] - '0';
            }
        }
    }

    set<array<int, 4>> q;
    q.insert({0, sx, sy, dir});
    while(!q.empty()){
        auto f = *q.begin(); q.erase(q.begin());
        int x= f[1], y =f[2], dir = f[3];
        int val = f[0];
        if (D[x][y][dir] != -1) continue;
        D[x][y][dir] = val;

        if (G[x][y] == 'S'){
            cout << val << '\n';
            return;
        }
        
        // spin
        int nd = (dir+1)%4;
        if (D[x][y][nd] == -1){
            q.insert({val + T, x, y, nd});
        }

        // move
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        int ndir = -1;
        auto res = getNext(nx, ny, dir);
        nx = res[0], ny = res[1], ndir = res[2];
        if (inGrid(nx, ny) && G[nx][ny] != 'T' && D[nx][ny][ndir] == -1){
            q.insert({val + 1, nx, ny, ndir});
        }

        nd = (dir + 3) % 4;
        nx = x + dx[nd];
        ny = y + dy[nd];
        ndir = -1;
        res = getNext(nx, ny, dir);
        nx = res[0], ny = res[1], ndir = res[2];
        if (inGrid(nx, ny) && G[nx][ny] != 'T' && D[nx][ny][ndir] == -1){
            q.insert({val + 1, nx, ny, ndir});
        }

    }

    cout << "-1\n";




}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }   
    return 0;
}