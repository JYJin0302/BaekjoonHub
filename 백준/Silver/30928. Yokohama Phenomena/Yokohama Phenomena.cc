#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
char grid[11][11];

ll dp[11][11];
ll tmp[11][11];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inGrid(int x, int y){
return x >= 0 && x < n && y >= 0 && y < m;
}


void solve(){

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m;j++) cin >> grid[i][j];
    }

    string s = "YOKOHAMA";
    for(int i =0; i < n; i++){
        for(int j =0 ; j < m; j++){
            if (grid[i][j] == 'Y') dp[i][j] = 1;
        }
    }
    for(int i = 1; i < 8; i++){
        char c = s[i];

        memset(tmp, 0, sizeof(tmp));
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if (grid[j][k] == c){
                    for(int d = 0; d < 4; d++){
                        int nj = j + dx[d];
                        int nk = k +dy[d];
                        if (inGrid(nj, nk)) tmp[j][k] += dp[nj][nk];
                    }
                }
            }
        }

        swap(dp, tmp);
    }

    ll ans = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            ans += dp[i][j];
        }
    }
    cout << ans;




}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
