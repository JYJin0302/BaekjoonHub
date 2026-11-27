#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n;
int dx[] = {-1, 0, 1 ,0};
int dy[] = {0, 1, 0, -1};
bool inGrid(int x, int y){
    return x>= 1 &&  x <= 2 * n && y >= 1 && y <= n;
}

bool vis[44][22];
vector<array<int, 3>> Q[200];
string dir = "URDL"; //

int mv[200];

void solve(){
    
    cin >> n;
    
    cout << n + 1 << ' '<< 1 << '\n';
    cout << n*2 << '\n';

    cout << "0\n";
    cout << "U 3000\n";

    vector<int> ord = {2, 1, 0, 1};


    int cx = n;
    int cy = 1;
    for(int i = 1; i < n*2; i++){

        int xx = cx, yy = cy;
        vis[xx][yy] = 1;
        if (xx <= n){
            // upward
            for(int j = i; j < n*2; j++){
                if (xx != 1 && !vis[xx - 1][yy]) {
                    Q[j].push_back({xx, yy, 0});
                    xx--;
                }
                else if (yy < n){
                    Q[j].push_back({xx, yy, 1});
                    yy++;
                }
                vis[xx][yy] = 1;
            }

        }
        else{
            // downward
            for(int j = i; j < n*2; j++){
                if (xx != n*2 && !vis[xx + 1][yy]) {
                    Q[j].push_back({xx, yy, 2});
                    xx++;
                }
                else if (yy < n){
                    Q[j].push_back({xx, yy, 1});
                    yy++;
                }
                vis[xx][yy] = 1;
            }
        }

        mv[i] = ord[(i-1)%4];
        cx += dx[mv[i]];
        cy += dy[mv[i]];
    }

    for(int i =1; i < n*2; i++){
        //cout << "State; " << i << '\n';
        cout << (int)Q[i].size() << '\n';
        for(auto f: Q[i]){
            cout << f[0] << ' ' << f[1] << ' ' << dir[f[2]] << '\n';
        }
        cout << dir[mv[i]] << ' ' << 3000 << '\n';
        //cout << '\n';
    }


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
