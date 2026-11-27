#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
map<char, int> ddx;

string ts = "NEWS";
int A[111][111];

bool no[111][111][111][4]; // time, x, y, dir

bool inGrid(int x, int y){
    return x >= 0 && x <= 100 && y >= 0 && y <= 100;
}

bool isCloud(int x, int y){
    if (!inGrid(x, y)) return 0;
    return A[x][y];
}

bool checkValid(int t, int x, int y, int mv, int c_dir){
    int cx = x - dx[c_dir] * t;
    int cy = y - dy[c_dir] * t;

    bool ok = 0;
    for(int a : {0, -1}){
        for(int b : {0, 1}){
            if (!isCloud(cx+a, cy+b)) ok = 1;
        }
    }

    if (!ok) {
        return 0;
    }

    if (c_dir == mv) return 1;

    if (c_dir == (mv + 2) % 4){
        ok = 1;
        if (mv == 0){
            // up
            if (isCloud(cx, cy + 1) && isCloud(cx-1, cy+1)) ok = 0;
            if (isCloud(cx, cy + 2) && isCloud(cx-1, cy+2)) ok = 0;
        }
        else if (mv == 1){
            // right
            if (isCloud(cx, cy) && isCloud(cx, cy+1)) ok = 0;
            if (isCloud(cx+1, cy) && isCloud(cx+1, cy+1)) ok = 0;
        }
        else if (mv == 2){
            // down
            if (isCloud(cx, cy) && isCloud(cx - 1, cy)) ok = 0;
            if (isCloud(cx, cy - 1) && isCloud(cx - 1, cy - 1)) ok = 0;
        }
        else{
            // left
            if (isCloud(cx - 1, cy) && isCloud(cx - 1, cy + 1)) ok = 0;
            if (isCloud(cx - 2, cy) && isCloud(cx - 2, cy + 1)) ok = 0;
        }
        return ok;
    }
    
    c_dir = (c_dir + 2) % 4;

    if (c_dir > mv) swap(c_dir, mv);

    if  (c_dir == 0 && mv == 1){
        return !isCloud(cx, cy + 1);
    }
    else if (c_dir == 1 && mv == 2){
        return !isCloud(cx, cy);
    }
    else if (c_dir == 2 && mv == 3){
        return !isCloud(cx-1, cy);
    }
    else if (c_dir == 0 && mv == 3){
        return !isCloud(cx-1, cy + 1);
    }
    return 0;
}

int D[333][111][111];

void solve(){   

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
// N E S W
    ddx['N'] = 0;
    ddx['E'] = 1;
    ddx['S'] = 2;
    ddx['W'] = 3;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){

        char dd;
        cin >> dd;

        int cloud_dir = ddx[dd];

        int k;
        cin >> k;
        vector<pair<int, int>> P;
        for(int j = 0 ;j < k; j++){
            int a, b;
            cin >> a>> b;
            P.push_back(mp(a, b));
        }
        
        memset(A, 0, sizeof A);
        for(int j =0 ;j < k; j++){
            auto[a,b] = P[j];
            auto[c,d] = P[(j+1)%k];
            if (b == d){
                if (a < c){
                    for(int f = a; f < c; f++){
                        A[f][b]++;
                    }
                }
                else{
                    for(int f = c; f < a; f++){
                        A[f][b]--;
                    }
                }
            }
        }

        for(int a = 0; a <= 100; a++){
            for(int b = 99; b >= 0; b--){
                A[a][b] += A[a][b+1];
            }
        }
        
        // check

        if (cloud_dir == 0){
            for(int t = 0; t <= 100; t++){
                for(int tx = 0; tx <= 100; tx++){
                    for(int ty = t;ty <= 100; ty++){
                        for(int d = 0; d < 4; d++){
                            if (!checkValid(t, tx, ty, d, cloud_dir)) {
                                no[t][tx][ty][d] = 1;
                                //if(t <= 10) cout << "T :" << t << ' ' << tx << ' ' << ty << ' '<< d  << ' ' <<cloud_dir << '\n';
                            }
                        }
                    }
                }
            }
        }
        else if (cloud_dir == 1){
            for(int t = 0; t <= 100; t++){
                for(int tx = t; tx <= 100; tx++){
                    for(int ty = 0; ty <= 100; ty++){
                        for(int d = 0; d < 4; d++){
                            if (!checkValid(t, tx, ty, d, cloud_dir)) {
                                no[t][tx][ty][d] = 1;
                                //if(t <= 10) cout << "T :" << t << ' ' << tx << ' ' << ty << ' '<< d  << ' ' <<cloud_dir << '\n';
                            }
                        }
                    }
                }
            }
        }
        else if (cloud_dir == 2){
            for(int t = 0; t <= 100; t++){
                for(int tx = 0; tx <= 100; tx++){
                    for(int ty = 0;ty <= 100 - t; ty++){
                        for(int d = 0; d < 4; d++){
                            if (!checkValid(t, tx, ty, d, cloud_dir)) {
                                no[t][tx][ty][d] = 1;
                                //if(t <= 10) cout << "T :" << t << ' ' << tx << ' ' << ty << ' '<< d  << ' ' <<cloud_dir << '\n';
                            }
                        }
                    }
                }
            }
        }
        else{
            for(int t = 0; t <= 100; t++){
                for(int tx = 0; tx <= 100 - t; tx++){
                    for(int ty = 0;ty <= 100; ty++){
                        for(int d = 0; d < 4; d++){
                            if (!checkValid(t, tx, ty, d, cloud_dir)) {
                                no[t][tx][ty][d] = 1;
                                //if(t <= 10) cout << "T :" << t << ' ' << tx << ' ' << ty << ' '<< d  << ' ' <<cloud_dir << '\n';
                            }
                        }
                    }
                }
            }
        }
        
    }

    D[0][sx][sy] = 1;
    queue<array<int, 3>> q;
    q.push({0, sx, sy});

    int ans = 500;
    while(!q.empty()){
        auto f= q.front(); q.pop();

        int d = f[0];
        int a = f[1], b = f[2];

        if (a == ex && b == ey){
            cout << d << '\n';
            return;
        }
        if(d > 100){
            ans = min(ans, abs(ex - a) + abs(ey - b) + d);
            continue;
        }

        if (D[d+1][a][b] == 0){
            D[d+1][a][b] = 1;
            q.push({d+1, a, b});
        }
        for(int dir = 0; dir < 4; dir++){
            int na = a + dx[dir];
            int nb = b + dy[dir];

            if(inGrid(na, nb) && !no[d][a][b][dir]){
                if(D[d+1][na][nb] == 0){
                    D[d+1][na][nb] = 1;
                    q.push({d+1, na, nb});
                }
            }
        }
    }
    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}