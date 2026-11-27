#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool K[10][10];
int dx [] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool inGrid(int x, int y){
    return x>= 0 && x < 8 && y >= 0 && y < 8;
}




vector<array<int, 4>> mv;

int dist[10][10];
int from[10][10];

void bfs(int x, int y, int tx, int ty){
    memset(from, -1, sizeof from);
    memset(dist, -1 ,sizeof dist);

    dist[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(mp(x, y));
    while(!q.empty()){
        auto[a,b] = q.front(); q.pop();
        for(int i =0 ;i < 8; i++){
            int na =a + dx[i];
            int nb =b  + dy[i];
            if (inGrid(na, nb) && dist[na][nb] == -1){
                dist[na][nb] = dist[a][b] + 1;
                from[na][nb] = i;
                q.push(mp(na, nb));
            }
        }
    }

    while(tx != x || ty != y){
        int nx = tx - dx[from[tx][ty]];
        int ny = ty - dy[from[tx][ty]];

        // nx, ny -> tx, ty
        mv.push_back({nx, ny, tx, ty});
        tx = nx, ty = ny;
    }


}


void solve(){
    int k;
    cin >> k;

    vector<pair<int, int>> nn;
    for(int i =0 ; i < k; i++){
        string s;
        cin >> s;

        int v1 = s[0] - 'a';
        int v2 = s[1] - '1';

        nn.push_back(mp(v1, v2));
        K[v1][v2] = 1;
    }
    sort(all(nn));

    int tx = 0, ty = 0;
    for(auto[a,b] :nn){
        bfs(a, b, tx, ty);

        tx++;
        if (tx == 8){
            ty++;
            tx = 0;
        }
    }

    // for(auto f: mv){
    //     for(int j =0 ;j < 4; j++) cout << f[j] << ' ';
    //     cout << '\n';
    // }

    vector<string> ans;
    
    int tn = (int)mv.size();
    vector<bool> used(tn);

    int uCnt = 0;
    while(uCnt < tn){
        int pre = uCnt;
        for(int j = 0; j < tn; j++){
            if(used[j]) continue;

            int x1 = mv[j][0];
            int y1 = mv[j][1];
            int x2 = mv[j][2];
            int y2 = mv[j][3];
            if (K[x1][y1] && !K[x2][y2]){
                used[j] = 1;
                uCnt++;

                K[x2][y2] = 1;
                K[x1][y1] = 0;
                string res;
                res += char('a'+ x1);
                res += char('1' + y1);
                res += '-';
                res += char('a' + x2);
                res += char('1' + y2);
                ans.push_back(res);
            }
        }
        if (uCnt == pre) break;
    }

    cout << (int)ans.size() << '\n';
    for(auto f : ans) cout <<f << '\n';



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
