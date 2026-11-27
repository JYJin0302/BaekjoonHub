#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m;
char G[1010][1010];

vector<int> lst[1010][1010];


vector<int> adj[1000101];
int col[1001010];

vector<int> L[2];
void dfs(int v){
    L[col[v]].push_back(v);
    for(auto f: adj[v]){
        if (col[f] == -1){
            col[f] = 1 - col[v];
            dfs(f);
        }
        else assert(col[f] == 1 - col[v]);
    }
}

void solve(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> G[i][j];
        }
    }

    vector<int> BLst;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (G[i][j] == '.') continue;

            int cd = (i-1) * m + j;
            bool t = ('A' <= G[i][j] && G[i][j] <= 'Z');
            bool ok = 0;
            if (i != n && G[i+1][j] == G[i][j]){
                if (t){
                    // right
                    if(j != m && G[i][j+1] == '.' && G[i+1][j+1] == '.'){
                        ok = 1;
                        lst[i][j+1].push_back(cd);
                        lst[i+1][j+1].push_back(cd);
                    }
                }
                else{
                    // left
                    if(j != 1 && G[i][j-1] == '.' && G[i+1][j-1] == '.'){
                        ok = 1;
                        lst[i][j-1].push_back(cd);
                        lst[i+1][j-1].push_back(cd);
                    }
                }
            }
            else if(j != m && G[i][j+1] == G[i][j]){
                if (t){
                    // down
                    if (i != n && G[i+1][j] == '.' && G[i+1][j+1] == '.'){
                        ok = 1;
                        lst[i+1][j].push_back(cd);
                        lst[i+1][j+1].push_back(cd);
                    }
                }
                else{
                    // up
                    if(i != 1 && G[i-1][j] == '.' && G[i-1][j+1] == '.'){
                        ok = 1;
                        lst[i-1][j].push_back(cd);
                        lst[i-1][j+1].push_back(cd);
                    }
                }
            }

            if (ok){
                BLst.push_back(cd);
            }
        }
    }


    for(int i =1; i <= n; i++){
        for(int j =1 ; j <= m; j++){
            if((int)lst[i][j].size() == 2){
                int u = lst[i][j][0];
                int v = lst[i][j][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
    
    vector<int> ansLst;

    memset(col, -1, sizeof col);
    for(auto i : BLst){
        if(col[i] == -1){
            L[0].clear();
            L[1].clear();
            col[i] = 0;
            dfs(i);

            int s0 = (int)L[0].size();
            int s1 = (int)L[1].size();
            if(s0 >= s1){
                for(auto f : L[0]){
                    ansLst.push_back(f);
                }
            }
            else{
                for(auto f :L[1]){
                    ansLst.push_back(f);
                }
            }

        }
    }

    for(auto f :ansLst){
        int x = (f-1) / m + 1;
        int y = (f-1) % m + 1;


        bool t = ('A' <= G[x][y] && G[x][y] <= 'Z'); // down right ?
        bool t2 = (x != n && G[x+1][y] == G[x][y]); // left right ?

        int sx = x, sy = y;
        if (t && t2){
            // right
        }
        else if (t){
            // down
        }
        else if (t2){
            // left
            sy--;
        }
        else{
            // up
            sx--;
        }

        int tt = (sx % 3) * 3 + sy % 3;
        for(int a = 0;a < 2; a++){
            for(int b= 0;b < 2 ;b ++){
                G[sx+a][sy+b] = char('0' + tt);
            }
        }
    }

    for(int i= 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(isalpha(G[i][j])){
                int tt = (i % 3) * 3 + j % 3;

                if (i != n && G[i+1][j] == G[i][j]){
                    G[i+1][j] = G[i][j] = char('0' + tt);
                }
                else{
                    G[i][j+1] = G[i][j] = char('0' + tt);
                }
            }
        }
    }

    cout << (int)ansLst.size() << '\n';
    for(int i= 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << G[i][j];
        }
        cout << '\n';
    }



}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
