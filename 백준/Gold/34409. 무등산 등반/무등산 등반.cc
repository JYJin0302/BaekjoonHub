#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
int G[505][505];

ll dist[505][505];

int dx [] = {-1, 0, 1,0};
int dy[] = {0, 1, 0, -1};
bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(){
    cin >> n >> m;
    
    int sx, sy;
    cin >> sx >> sy;
    sx--, sy--;

    int a, b, c;
    cin >> a>> b >> c;


    int mx = 0;
    for(int i =0 ; i < n;i++){
        for(int j = 0 ;j  <m ;j++){
            cin >> G[i][j];
            mx = max(mx, G[i][j]);
        }
    }
    memset(dist, -1, sizeof dist);

    set<array<ll, 3>> st;
    st.insert({0, sx, sy});
    while(!st.empty()){
        auto f = *st.begin();
        st.erase(st.begin());

        int x = f[1], y= f[2];
        if (dist[x][y] != -1) continue;
        dist[x][y] = f[0];

        if (G[x][y] == mx){
            cout << f[0] << '\n';
            return;
        }

        for(int d= 0 ; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(inGrid(nx, ny) && dist[nx][ny] == -1 && abs(G[nx][ny] - G[x][y]) <= c){
                ll nd = f[0];
                ll dif = G[nx][ny] - G[x][y];
                if (dif == 0) nd++;
                else if (dif > 0) nd += dif * a;
                else nd += -dif * b;
                st.insert({nd, nx, ny});
            }
        }
    }
    cout << -1<< '\n';

}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}