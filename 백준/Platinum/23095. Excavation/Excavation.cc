#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair

char grid[101][101];

int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dNx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dNy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int n;
bool inGrid(int x, int y){
    return x>= 0 && x <n &&y >= 0 && y < n;
}

vector<int> adj[10101];
bool vs[10101];
vector<pair<int, int>> ans;

void dfs(int v, int pv = -1){
    vs[v] = 1;
    for(auto f : adj[v]) if(f != pv && !vs[f]){
        dfs(f, v);
    }
    ans.push_back(mp(v, pv));
}

void solve(){

    cin >> n;

    char c;
    cin >> c;

    int cnt = 0;
    vector<bool> isP(n*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if (grid[i][j] == c) {
                    isP[i*n+j] = 1;
                    cnt++;
            }
        }
    }

    if (cnt == 0){
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (grid[i][j] == c){
                int v = i*n + j;
                isP[v] = 1;

                switch (c){
                case 'K':
                    for(int f = 0; f <8; f++){
                        int ni = i + dx[f];
                        int nj = j + dy[f];

                        if (inGrid(ni, nj) && isP[ni*n+nj]){
                            adj[v].push_back(ni*n+nj);
                        }
                    }

                    break;
                case 'Q':
                    for(int f = 0; f < 8; f++){
                        int ni = i + dx[f];
                        int nj = j + dy[f];

                        while (inGrid(ni, nj)){
                            if(isP[ni*n+nj]) adj[v].push_back(ni*n+nj);
                            ni += dx[f];
                            nj += dy[f];
                        }
                    }

                    break;

                case 'N':
                    for(int f = 0; f <8; f++){
                        int ni = i + dNx[f];
                        int nj = j + dNy[f];

                        if (inGrid(ni, nj) && isP[ni*n+nj]){
                            adj[v].push_back(ni*n+nj);
                        }
                    }

                    break;

                case 'B':
                    for(int f = 4; f < 8; f++){
                        int ni = i + dx[f];
                        int nj = j + dy[f];

                        while (inGrid(ni, nj)){
                            if(isP[ni*n+nj]) adj[v].push_back(ni*n+nj);
                            ni += dx[f];
                            nj += dy[f];
                        }
                    }

                    break;

                case 'R':
                    for(int f = 0; f < 4; f++){
                        int ni = i + dx[f];
                        int nj = j + dy[f];

                        while (inGrid(ni, nj)){
                            if(isP[ni*n+nj]) adj[v].push_back(ni*n+nj);
                            ni += dx[f];
                            nj += dy[f];
                        }
                    }
                    break;
                }
            }

        }
    }


    int ix = 0;
    while(ix < n*n && !isP[ix]) ix++;

    dfs(ix);

    if(ans.size() != cnt) cout <<"NO\n";
    else {
        cout <<"YES\n";

        for(int i = 0; i < ans.size()-1; i++){

            int l = ans[i].first;
            int r = ans[i].second;

            cout << l / n + 1 << ' ' << l % n + 1 << ' ' << r/n+1 << ' ' << r%n+1 << '\n';

        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
