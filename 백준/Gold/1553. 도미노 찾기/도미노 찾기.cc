#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int n, m;

int G[10][10];
int ans = 0;

bool usedD[10][10];
bool usedG[10][10];


void choose(int i, int j){
    if (j == m) i++, j = 0;
    if (i == n){
        ans++;
        return;
    }
    
    if (usedG[i][j]) {
        choose(i, j + 1);
        return;
    }

    if (j+1 != m && !usedG[i][j+1]){
        int v1 = G[i][j];
        int v2 = G[i][j+1];
        if (!usedD[v1][v2]){
            usedG[i][j+1] = 1;
            usedD[v1][v2] = usedD[v2][v1] = 1;

            choose(i, j+1);

            usedG[i][j+1] = 0;
            usedD[v1][v2] = usedD[v2][v1] = 0;
        }
    }

    if (i+1 != n && !usedG[i+1][j]){
        int v1 = G[i][j];
        int v2 = G[i+1][j];
        if (!usedD[v1][v2]){
            usedG[i+1][j] = 1;
            usedD[v1][v2] = usedD[v2][v1] = 1;

            choose(i, j+1);

            usedG[i+1][j] = 0;
            usedD[v1][v2] = usedD[v2][v1] = 0;
        }
    }

}

void solve(){
    
    //cin >> n >> m;
    n = 8, m = 7;
    for(int i =0; i < n;i++){
        for(int j = 0 ;j < m;j++){
            char c;
            cin >> c;
            G[i][j] = c - '0';
        }
    }

    choose(0, 0);
    cout << ans << '\n';

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