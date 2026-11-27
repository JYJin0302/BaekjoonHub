#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define mp make_pair
#define x first
#define y second

int n;
pair<ld, ld> s, e, A[1010];
ld v1, v2;

const ld eps = 1e-5;

ld xMin, xMax, yMin, yMax;

ld dist[1010];

ld path[1010][1010];

ld getDist(ld x1, ld y1, ld x2, ld y2){
    return sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


void fillPath(){

    for(int i = 0; i < n;i++){
        path[i][i] = 0;
        for(int j = i+1; j < n; j++){
            path[i][j] = getDist(A[i].x , A[i].y, A[j].x, A[j].y) / v2;
            path[j][i] = path[i][j];
        }
    }

    for(int f = n; f <= n+1; f++){
        for(int i = 0; i < n; i++){
            // path[n][i]
            path[f][i] = getDist(A[f].x, A[f].y, A[i].x, A[i].y)/ v1;

            //cout << "Get:"<< f << ' ' <<i <<'\n';
            ld xl, xr, yl, yr, res = 1e18;

            xl = xMin, xr = xMax;
            yl = yr = yMin;

            //cout << "Go:" << xl << ' ' <<yl << " <-> "<< xr << ' '<< yr <<'\n';
            while(xl + eps < xr || yl + eps < yr){
                ld x1 = (2*xl + xr)/3;
                ld x2 = (xl + 2*xr)/3;

                ld val1 = getDist(x1, yl, A[f].x, A[f].y) / v1 + getDist(x1, yl, A[i].x, A[i].y) / v2;
                ld val2 = getDist(x2, yl, A[f].x, A[f].y) / v1 + getDist(x2, yl, A[i].x, A[i].y) / v2;

                if (val1 >= val2) xl = x1;
                else xr = x2;

                //cout << min(val1 , val2)<< '\n';
                res = min({res, val1, val2});
            }

            xl = xMin, xr = xMax;
            yl = yr = yMax;
            //cout << "Go:" << xl << ' ' <<yl << " <-> "<< xr << ' '<< yr <<'\n';
            while(xl + eps < xr || yl + eps < yr){
                ld x1 = (2*xl + xr)/3;
                ld x2 = (xl + 2*xr)/3;

                ld val1 = getDist(x1, yl, A[f].x, A[f].y) / v1 + getDist(x1, yl, A[i].x, A[i].y) / v2;
                ld val2 = getDist(x2, yl, A[f].x, A[f].y) / v1 + getDist(x2, yl, A[i].x, A[i].y) / v2;

                if (val1 >= val2) xl = x1;
                else xr = x2;
                //cout << min(val1 , val2)<< '\n';
                res = min({res, val1, val2});
            }

            xl = xr = xMin;
            yl = yMin, yr = yMax;
            //cout << "Go:" << xl << ' ' <<yl << " <-> "<< xr << ' '<< yr <<'\n';
            while(xl + eps < xr || yl + eps < yr){
                ld y1 = (2*yl + yr)/3;
                ld y2 = (yl + 2*yr)/3;

                ld val1 = getDist(xl, y1, A[f].x, A[f].y) / v1 + getDist(xl, y1, A[i].x, A[i].y) / v2;
                ld val2 = getDist(xl, y2, A[f].x, A[f].y) / v1 + getDist(xl, y2, A[i].x, A[i].y) / v2;

                if (val1 >= val2) yl = y1;
                else yr = y2;
                //cout << min(val1 , val2)<< '\n';
                res = min({res, val1, val2});
            }

            xl = xr = xMax;
            yl = yMin, yr = yMax;
            //cout << "Go:" << xl << ' ' <<yl << " <-> "<< xr << ' '<< yr <<'\n';
            while(xl + eps < xr || yl + eps < yr){
                ld y1 = (2*yl + yr)/3;
                ld y2 = (yl + 2*yr)/3;

                ld val1 = getDist(xl, y1, A[f].x, A[f].y) / v1 + getDist(xl, y1, A[i].x, A[i].y) / v2;
                ld val2 = getDist(xl, y2, A[f].x, A[f].y) / v1 + getDist(xl, y2, A[i].x, A[i].y) / v2;

                if (val1 >= val2) yl = y1;
                else yr = y2;
                //cout << min(val1 , val2)<< '\n';
                res = min({res, val1, val2});
            }

            path[f][i] = min(path[f][i], res);
            path[i][f] = path[f][i];
        }
    }


    // dist[n][n+1]

    vector<tuple<ld, ld, ld, ld>> tt;
    tt.push_back({xMin, xMax, yMin, yMin});
    tt.push_back({xMin, xMax, yMax, yMax});
    tt.push_back({xMin, xMin, yMin, yMax});
    tt.push_back({xMax, xMax, yMin, yMax});

    //cout << "Curr:"<< xMin << ' ' << xMax << ' ' << yMin<<' ' <<yMax<<'\n';
    ld x1l, x1r, y1l, y1r;
    ld x2l, x2r, y2l, y2r;

    ld tres = getDist(A[n].x, A[n].y, A[n+1].x, A[n+1].y) / v1;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
           // cout << "GOGO:" << i << ' ' <<j << '\n';
            tie(x1l, x1r, y1l, y1r) = tt[i];
            tie(x2l, x2r, y2l, y2r) = tt[j];

               // cout << "Test : "<< x1l << ' '<< y1l << " <-> " << x1r << ' ' << y1r << '\n';
            while(x1l + eps < x1r || y1l + eps < y1r){
                //cout << "Test : "<< x1l << ' '<< y1l << " <-> " << x1r << ' ' << y1r << '\n';

                ld nx1 = (x1l*2 + x1r)/3;
                ld nx2 = (x1l + 2*x1r)/3;
                ld ny1 = (y1l*2 + y1r)/3;
                ld ny2 = (y1l + 2*y1r)/3;

                ld val1 = 1e18;
                tie(x2l, x2r, y2l, y2r) = tt[j];
                while(x2l + eps < x2r || y2l + eps < y2r){
                    ld nnx1 = (x2l*2 + x2r)/3;
                    ld nnx2 = (x2l + 2*x2r)/3;
                    ld nny1 = (y2l*2 + y2r)/3;
                    ld nny2 = (y2l + 2*y2r)/3;

                    ld vval1 = getDist(A[n].x, A[n].y, nx1, ny1)/v1 + getDist(nx1, ny1, nnx1, nny1) / v2 + getDist(nnx1, nny1, A[n+1].x, A[n+1].y) / v1;
                    ld vval2 = getDist(A[n].x, A[n].y, nx1, ny1)/v1 + getDist(nx1, ny1, nnx2, nny2) / v2 + getDist(nnx2, nny2, A[n+1].x, A[n+1].y) / v1;

                    if (vval1 < vval2) {
                        x2r = nnx2;
                        y2r = nny2;
                    }
                    else{
                        x2l = nnx1;
                        y2l = nny1;
                    }

                    val1 = min({val1, vval1, vval2});
                }


                ld val2 = 1e18;
                tie(x2l, x2r, y2l, y2r) = tt[j];
                while(x2l + eps < x2r || y2l + eps < y2r){
                    ld nnx1 = (x2l*2 + x2r)/3;
                    ld nnx2 = (x2l + 2*x2r)/3;
                    ld nny1 = (y2l*2 + y2r)/3;
                    ld nny2 = (y2l + 2*y2r)/3;

                    ld vval1 = getDist(A[n].x, A[n].y, nx2, ny2)/v1 + getDist(nx2, ny2, nnx1, nny1) / v2 + getDist(nnx1, nny1, A[n+1].x, A[n+1].y) / v1;
                    ld vval2 = getDist(A[n].x, A[n].y, nx2, ny2)/v1 + getDist(nx2, ny2, nnx2, nny2) / v2 + getDist(nnx2, nny2, A[n+1].x, A[n+1].y) / v1;

                    if (vval1 < vval2) {
                        x2r = nnx2;
                        y2r = nny2;
                    }
                    else{
                        x2l = nnx1;
                        y2l = nny1;
                    }

                    val2 = min({val2, vval1, vval2});
                }


                if(val1 > val2){
                    x1l = nx1;
                    y1l = ny1;
                }
                else{
                    x1r = nx2;
                    y1r = ny2;
                }

                tres = min({tres, val1, val2});
            }

        }
    }
    path[n][n+1] = tres;
    path[n+1][n] = tres;

}

void solve(){
    cin >> v1 >> v2;
    cin >> xMin >> yMin >> xMax>> yMax;
    cin >> s.x >> s.y >> e.x >> e.y;


    cin >> n;

    for(int i= 0; i < n; i++) cin >> A[i].x >> A[i].y;
    A[n] = s;
    A[n+1] = e;

    fillPath();

//    for(int i = 0; i< n+2; i++){
//        for(int j = 0; j < n+2; j++){
//            cout << path[i][j] << ' ';
//        }
//        cout << '\n';
//    }


    for(int i = 0; i <= n+1; i++) dist[i] = 1e17;
    // n :start, n+1 : end
    priority_queue<pair<ld, int>> pq;
    pq.push({0, n});
    while(!pq.empty()){

        ld val;
        int curr;

        tie(val , curr) = pq.top();
        pq.pop();

        if(dist[curr] == 1e17){
            dist[curr] = -val;
        }
        else continue;

        //cout <<"upd: " << curr<< ' ' << -val << '\n';

        for(int i = 0; i <= n+1; i++){
            if (dist[i] == 1e17){
                pq.push(mp(val - path[curr][i], i));
            }
        }

    }

    cout << dist[n+1];

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << setprecision(13);
    solve();
    return 0;
}
