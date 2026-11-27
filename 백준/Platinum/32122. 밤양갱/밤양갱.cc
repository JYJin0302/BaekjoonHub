#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int A[101][101];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1,0 , -1};
bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

vector<int> adj[10101];

int L[10101], R[10101];

bool vis[10010];
int lim = 1;
bool go(int x, int L[], int R[]){
    if (vis[x]) return 0;
    vis[x] = 1;

    for(auto f : adj[x]){
        if(f > lim) continue;
        if (R[f] == -1 || go(R[f], L, R)){
            R[f] = x;
            L[x] = f;
            return 1;
        }
    }
    return 0;
}

void solve(){
    
    cin >> n;
    
    vector<bool> od(n*n+10);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];

            int ti = (i+j) % 2;
            od[A[i][j]] = ti;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j =0 ; j < n; j++){
            for(int f = 0; f < 4; f++){
                int ni = i + dx[f];
                int nj = j + dy[f];
                if (inGrid(ni ,nj)){
                    adj[A[i][j]].push_back(A[ni][nj]);
                }
            }
        }
    }

    memset(L, -1, sizeof L);
    memset(R, -1, sizeof R);

    vector<int> res;
    for(int i = 1; i <= n*n; i++){
        lim = i;

        memset(vis, 0, sizeof vis);
        if(od[i] && go(i, L, R)) res.push_back(i);
        else if ( !od[i] && go(i, R, L)) res.push_back(i);
    }

    for(auto f : res) cout << f << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}