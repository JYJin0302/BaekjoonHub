#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool obs[111][111];
int vis[4][111][111];
bool inGrid(int x, int y){
    return x >= 0 && x <= 100 && y >= 0 && y <= 100;
}

void solve(int n){
    
    ll a, b, d;
    cin >> a >> b >> d;

    for(int k = 0; k < 4; k++){
        for(int i =0 ; i <= 100; i++){
            for(int j = 0; j <= 100; j++) vis[k][i][j] = -1;
        }
    }

    memset(obs, 0 ,sizeof obs);
    for(int i = 0; i < n ;i++){
        int x, y;
        cin >> x >> y;
        obs[x][y] = 1;
    }

    vis[2][a][b] = 0;
    int dir = 2; // left : -1
    int totd = 0;

    //cout << "simul start" << endl;
    while(totd < d && inGrid(a, b)){
       // cout << a << ' '<< b << ' '<< dir  << " || " << totd << ' ' << d << endl;
        ll na = a + dx[dir];
        ll nb = b + dy[dir];
        if (!inGrid(na, nb)){
            // end
            a = na, b = nb;
            totd++;
            ll dif = d - totd;
            a += dx[dir] * dif;
            b += dy[dir] * dif;
            cout << a << ' '<< b << '\n';
            return;
        }
        if (!obs[na][nb]){
            a = na, b = nb;
            totd++;

            if(vis[dir][a][b] != -1){
                // cycle
                ll dif = d - totd;
                ll cycleLen = totd - vis[dir][a][b];

                if (cycleLen == 0){
                    cout << a << ' ' << b << '\n';
                    return;
                }

                dif %= cycleLen;
                d = totd + dif;
            }
            else vis[dir][a][b] = totd;
        }
        else {
            dir = (dir + 3) % 4;

            if(vis[dir][a][b] != -1){
                // cycle
                ll dif = d - totd;
                ll cycleLen = totd - vis[dir][a][b];

                if (cycleLen == 0){
                    cout << a << ' ' << b << '\n';
                    return;
                }

                dif %= cycleLen;
                d = totd + dif;
            }
            else vis[dir][a][b] = totd;

        }
    }

    cout << a << ' '<< b << '\n';

    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t) {
        solve(t);
        cin >> t;
    }

    return 0;
}