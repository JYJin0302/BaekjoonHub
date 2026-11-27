#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define x first
#define y second

int n, m;
char G[10][10];
bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

pair<int, int> track[10];
bool vis[10][10][5][4]; // x, y, pc, dir

string pf[] = {"GOTO", "IF-OPEN", "FORWARD", "LEFT", "RIGHT"};
int sx, sy, ex, ey;

void simul(int len){
    
    memset(vis, 0, sizeof vis);
    int pc = 1;
    int cx = sx, cy = sy;
    int dir = 2;
    vis[cx][cy][pc][dir] = 1;

    while(1){
        // fetch
        if(cx == ex && cy == ey) {
            break;
        }
        pair<int, int> inst = track[pc];
        if (inst.x == 0){
            // goto
            pc = inst.y;
        }
        else if (inst.x == 1){
            // ifopen
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (inGrid(nx, ny) && G[nx][ny] != '#') pc = inst.y;
            else {
                pc++;
            }
        }
        else if(inst.x == 2){
            // forward
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (inGrid(nx, ny) && G[nx][ny] != '#') {
                cx = nx, cy = ny;
            }
            pc++;
        }
        else if (inst.x == 3){
            // left
            dir = (dir + 3) % 4;
            pc++;
        }
        else {
            // inst.x == 4;
            // right
            dir = (dir + 1) % 4;
            pc++;
        }
        if (pc > len) pc = 1;

        if (vis[cx][cy][pc][dir]) return;
        vis[cx][cy][pc][dir] = 1;
    }

    // Done
    cout << len << '\n';
    for(int i = 1; i <= len ;i++){
        cout << pf[track[i].x] << ' ';
        if (track[i].y) cout << track[i].y << ' ';
        cout << '\n';
    }
    //cout << string(10, '-') << endl;
    exit(0);
}

void choose(int ix, int sz){
    if (ix > sz){
        // go Simul
        simul(sz);
        return;
    }

    for(int i = 0; i < 5; i++){
        if(i <= 1){
            // GOTO, IF-OPEN
            for(int j = 1; j <= sz; j++){
                if(j == ix || j == ix + 1) continue;
                track[ix] = mp(i, j);
                choose(ix+1, sz);
            }
        }
        else {
            track[ix] = mp(i, 0);
            choose(ix+1, sz);
        }
    }
}
void solve(){
    cin >> n >> m;    

    for(int i =0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> G[i][j];
            if(G[i][j] == 'S'){
                sx = i, sy = j;
            }
            else if (G[i][j] == 'G'){
                ex = i, ey = j;
            }
        }
    }

    //cout << sx << ' '<< sy << ' ' << ex << ' ' << ey << '\n';

    for(int i = 1; i <= 4; i++){
        choose(1, i);
    }

    cout << "5\n";
    cout << "LEFT\n";
    cout << "IF-OPEN 5\n";
    cout << "RIGHT\n";
    cout << "GOTO 2\n";
    cout << "FORWARD\n";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}