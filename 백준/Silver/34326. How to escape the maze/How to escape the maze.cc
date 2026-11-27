#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char G[1010][1010];

void solve() {

    int n, m;
    cin >> n >> m;

    int sx, sy;
    for(int i =0 ;i < n; i++){
        for(int j =0 ; j < m; j++){
            cin >> G[i][j];

            if (G[i][j] == 'S'){
                sx = i, sy= j;
            }
        }
    }

    int dir = 0;
    if (sx == 0) dir = 2;
    if (sy == 0) dir = 1;
    if (sx == n-1) dir = 0;
    if (sy == m-1) dir = 3;

    int cnt1 = 0, cnt2 = 0;

    int tx = sx,ty =sy;
    int d = dir;
    while(G[tx][ty] != 'E'){
        d = (d + 3) % 4;
        int nx = tx + dx[d];
        int ny = ty + dy[d];
        while(G[nx][ny] == '*'){
            d = (d + 1) % 4;
            nx = tx + dx[d];
            ny = ty + dy[d];
        }
        tx = nx, ty = ny;
        cnt1++;
    }

    tx = sx,ty =sy;
    d = dir;
    while(G[tx][ty] != 'E'){
        d = (d + 1) % 4;
        int nx = tx + dx[d];
        int ny = ty + dy[d];
        while(G[nx][ny] == '*'){
            d = (d + 3) % 4;
            nx = tx + dx[d];
            ny = ty + dy[d];
        }
        tx = nx, ty = ny;
        cnt2++;
    }
    
    if (cnt1 < cnt2) cout << "LEFT IS BEST\n";
    else if (cnt1 > cnt2) cout << "RIGHT IS BEST\n";
    else cout << "SAME\n";
    

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}