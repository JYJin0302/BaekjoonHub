#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int Roff = 2e6 + 10;
int Loff = 2e6 + 10;
vector<int> Rpos[1001010]; // /
vector<int> Lpos[1001010]; // \

map<pair<int, int>, bool> vert;

void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A;
    for(int i = 0; i <  n;i++){
        int a, b;
        cin >> a>> b;
        A.push_back(mp(a, b));
        Loff = min(Loff, a + b);
        Roff = min(Roff, a - b);
    }

    for(int i = 0 ; i < n;i++){
        auto[a,b] = A[(i + n-1) % n];
        auto[c,d] = A[i];

        if (a == c){
            if (b > d) swap(b, d);
            for(int j = b; j < d; j++){
                Rpos[a - j - Roff].push_back(a);
                Lpos[a + j - Loff].push_back(a);
                vert[mp(a, j)] = 1;
            }
        }
        else{
            //b == d
            if (a > c) swap(a, c);
            for(int j = a; j < c; j++){
                Rpos[j - b - Roff].push_back(j);
                Lpos[j + b - Loff].push_back(j);
            }
        }
    }

    for(int i = 0; i < 1000000; i++){
        sort(all(Lpos[i]));
    }
    for(int i = 0; i < 1000000; i++){
        sort(all(Rpos[i]));
    }

    int sx, sy;
    cin >> sx >> sy;

    int dir = 0; // UR, DR, DL, UL
    while(m--){
       // cout << "GO: "<< sx << ' '<< sy << ' ' << dir << endl;
        if (dir == 0){
            int rdx = sx - sy - Roff;
            auto iter = lower_bound(all(Rpos[rdx]), sx) - Rpos[rdx].begin();

            int nx = Rpos[rdx][iter+1];
            int ny = nx - (sx - sy);

            cout << nx<< ' ' << ny << '\n';
            sx = nx, sy = ny;

            if (vert[mp(sx, sy)]) dir = 3;
            else dir = 1;
        }
        else if(dir == 1){
            int ldx = sx + sy - Loff;
            auto iter = lower_bound(all(Lpos[ldx]), sx) - Lpos[ldx].begin();

            int nx = Lpos[ldx][iter+1];
            int ny = (sx + sy) - nx;

            cout << nx<< ' ' << ny << '\n';
            sx = nx, sy = ny;

            if (vert[mp(sx, sy)]) dir = 2;
            else dir = 0;

        }
        else if (dir == 2){
            int rdx = sx - sy - Roff;
            auto iter = lower_bound(all(Rpos[rdx]), sx) - Rpos[rdx].begin();

            int nx = Rpos[rdx][iter-1];
            int ny = nx - (sx - sy);

            cout << nx<< ' ' << ny << '\n';
            sx = nx, sy = ny;

            if (vert[mp(sx, sy)]) dir = 1;
            else dir = 3;
        }
        else{
            int ldx = sx + sy - Loff;
            auto iter = lower_bound(all(Lpos[ldx]), sx) - Lpos[ldx].begin();

            int nx = Lpos[ldx][iter-1];
            int ny = (sx + sy) - nx;

            cout << nx<< ' ' << ny << '\n';
            sx = nx, sy = ny;

            if (vert[mp(sx, sy)]) dir = 0;
            else dir = 2;
        }
    }


}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}