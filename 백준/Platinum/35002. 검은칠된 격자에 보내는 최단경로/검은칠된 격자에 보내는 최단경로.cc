#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m;
bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
char G[777][777];
char tG[777][777];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void setup(int x){
    for(int i =0; i < n; i++){
        for(int j =0 ; j < m; j++){
            tG[i][j] = G[i][j];
            if (G[i][j] == '.') tG[i][j] = char('0' + x);
        }
    }
}


int D[777][777];
int sx, sy, ex, ey;
int getDist(){
    
    memset(D, -1, sizeof D);
    set<array<int, 3>> st;
    st.insert({int(tG[sx][sy] - '0'), sx, sy});
    while(!st.empty()){
        auto f= *st.begin();
        st.erase(st.begin());

        int a = f[1];
        int b = f[2];
        if (D[a][b] != -1) continue;
        D[a][b] = f[0];

        int cst = f[0];
        if (a == ex && b == ey) return f[0];

        for(int s = 0;s <4 ; s++){
            int na = a + dx[s];
            int nb = b + dy[s];
            if (inGrid(na, nb) && tG[na][nb] != '#' && D[na][nb] == -1){
                st.insert({cst + (int)(tG[na][nb] - '0'), na, nb});
            }
        }
    }
    return -1;
}

void solve(){
    
    cin >>n >> m;

    vector<pair<int, int>> pp;
    for(int i =0; i < n; i++){
        for(int j = 0; j < m;j++){
            cin >> G[i][j];
            if (G[i][j] == '.'){
                pp.push_back(mp(i, j));
            }
        }
    }

    cin >> sx >> sy >>ex >> ey;
    sx--, sy--, ex--, ey--;
    int D;
    cin >> D;

    int tar = -1;
    for(int t = 0; t <= 9; t++){
        setup(t);

        int d = getDist();
        if (d == -1){
            cout << -1 << '\n';
            return;
        }

       // cout << t << " | " << d << '\n';
        if(d <= D) tar = t;
        if (d == D){
            for(int i =0; i < n; i++){
                for(int j =0 ; j < m; j++){
                    cout << tG[i][j];
                }
                cout << '\n';
            }
            return;
        }

        if(t == 0 && d > D){
            cout << -1 << '\n';
            return;
        }
        if (t == 9 && d < D){
            cout << -1 << '\n';
            return;
        }
    }
    assert(tar != -1);

    int L = 0, R = (int)pp.size() - 1;
    while(L <= R){
        setup(tar);
        int md = (L+R)>>1;
        for(int j = 0; j <= md; j++){
            auto[a,b] = pp[j];
            tG[a][b]++;
        }

        int d = getDist();
        if (d == D){
            for(int i =0; i < n; i++){
                for(int j =0 ; j < m; j++){
                    cout << tG[i][j];
                }
                cout << '\n';
            }
            return;
        }

        if (d < D) L =md + 1;
        else R = md - 1;
    }

    cout << -1 << '\n';

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