#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

array<int, 3> rec[1010];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1 ,0 ,-1};

void solve(){
    
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int buk = 50;

    for(int i = 0; i < n; i+= buk){
        // simul
        int x = 0, y = 0;
        int dir = 0;
        for(int j = i; j < min(n, i + buk); j++){
            char c = s[j];
            if (c == 'U'){
                x += dx[dir];
                y += dy[dir];
            }
            else if (c == 'L'){
                dir = (dir + 3) % 4;
            }
            else{
                dir = (dir + 1) % 4;
            }
        }

        rec[i/buk] = {x, y, dir};
    }

    while(q--){
        int ix;
        cin >> ix;
        char c;
        cin >> c;

        s[ix-1] = c;
        int l = (ix-1)/buk*buk;
        
        int x = 0, y = 0;
        int dir = 0;
        for(int j = l; j < min(n, l+buk); j++){
            char c = s[j];
            if (c == 'U'){
                x += dx[dir];
                y += dy[dir];
            }
            else if (c == 'L'){
                dir = (dir + 3) % 4;
            }
            else{
                dir = (dir + 1) % 4;
            }
        }
        rec[(ix-1)/buk] = {x, y, dir};

        // cout << "REc: ";
        // for(int i = 0; i < n; i+= buk){
        //     cout << rec[i/buk][0] << ' ' << rec[i/buk][1] << ' ' << rec[i/buk][2] << " || ";
        // }
        // cout << '\n';


        x = 0, y = 0, dir = 0;
        for(int i = 0; i < n; i+= buk){
            // total
            int ix = i/buk;
            int nx = rec[ix][0];
            int ny = rec[ix][1];
            int ndir = rec[ix][2];

            if (dir == 0){
                x += nx;
                y += ny;
            }
            else if (dir == 1){
                x += ny;
                y -= nx;
            }
            else if (dir == 2){
                x -= nx;
                y -= ny;
            }
            else{
                x -= ny;
                y += nx;
            }
            dir = (dir + ndir) % 4;
        }

        int ans = 0;
        if ((x == 0 && y == 0) || dir != 0) ans = 0;
        else ans = 1;

        cout << ans << '\n';
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