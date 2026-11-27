#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m;

int G[1300][1300];
int C[1300][1300];

ll R[1300][1300];
ll L[1300][1300];
ll D[1300][1300];
ll getBox(int x1, int y1, int x2, int y2, ll A[][1300]){
    return A[x2][y2] - A[x1-1][y2] - A[x2][y1-1] + A[x1-1][y1-1];
}


void solve(){

    int q;
    cin >> n >> m >> q;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> G[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> C[i][j];
        }
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            if (G[i-1][j] != G[i][j] && G[i][j-1] != G[i][j]) R[i][j] = C[i][j];
            R[i][j] += R[i-1][j] + R[i][j-1] - R[i-1][j-1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= m; j++){
            if (G[i][j-1] != G[i][j]) L[i][j] = C[i][j];
            L[i][j] += L[i-1][j] + L[i][j-1] - L[i-1][j-1];
        }
    }

    for(int j = 1; j <= m; j++){
        for(int i = 2; i <= n; i++){
            if (G[i][j] != G[i-1][j]) D[i][j] = C[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= m; j++){
            D[i][j] += D[i-1][j] + D[i][j-1] - D[i-1][j-1];
        }
    }


    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll res = C[x1][y1];
        
        res += getBox(x1, y1 + 1, x1, y2, L);
        res += getBox(x1 + 1, y1, x2, y1, D);

        res += getBox(x1 + 1, y1 + 1, x2, y2, R);
        cout << res << '\n';
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