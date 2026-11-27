#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m;
int L[2020];
int R[2020];

int Dat[1010][1010];

vector<pair<int, int>> ask(string path){
    cout << "? " << path<< endl;
    int k;
    cin >> k;
    vector<pair<int, int>> sign;
    while(k--){
        int a, b;
        cin >> a>> b;
        sign.push_back(mp(a, b));
    }
    sort(all(sign));
    return sign;
}

void report(){
    int x= 1, y= 1;
    string path;
    while(x + y < n+m){
        if(x == n) {
            y++;
            path += 'R';
        }
        else if (y == m){
            x++;
            path += 'D';
        }
        else if (Dat[x+1][y] == 1){
            x++;
            path += 'D';
        }
        else if(Dat[x][y+1] == 1) {
            y++;
            path += 'R';
        }
        else{
            // something is wrong
            assert(0);
            return;
        }
    }
    cout << "! " << path << endl;
}

void solve(){

    memset(Dat, -1, sizeof Dat);
    
    
    cin >> n >> m;

    for(int i = 1; i <= n+m; i++){
        L[i] = 3030;
        R[i] = -1;
    }
    for(int i =0 ;i <= n; i++){
        Dat[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        Dat[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= m; j++){
            L[i+j] = min(L[i+j], i);
            R[i+j] = max(R[i+j], i);
        }
    }

    while(1){

        // print state
        // for(int i =1 ; i <= n; i++){
        //     for(int j =1; j <= m; j++){
        //         if (Dat[i][j] == -1) cout << "X";
        //         else cout << Dat[i][j];
        //     }
        //     cout << '\n';
        // }

        // for(int i = 2; i <= n+m; i++) cout << L[i] << ' ';
        // cout << '\n';
        // for(int i = 2; i <= n+m; i++) cout << R[i] << ' ';
        // cout << '\n';
        // cout << endl;
        int x = 1, y = 1;
        string path;
        vector<pair<int, int>> route;
        while(x + y < n + m){
            route.push_back(mp(x, y));
            if (x == n) {
                path += 'R';
                y++;
            }
            else if (y == m){
                path += 'D';
                x++;
            }
            else{
                int ni = x + y + 1;
                int l = L[ni], r= R[ni];
                int md = (l+r)>>1;

                if (abs(md - x) <= abs(md - x - 1)){
                    path += 'R';
                    y++;
                }
                else{
                    path += 'D';
                    x++;
                }
            }
        }
        route.push_back(mp(x, y));

        vector<pair<int, int>> sign = ask(path);

        for(auto[a,b] : route) Dat[a][b] = 0;
        for(auto[a,b] : sign) Dat[a][b] = 1;

        for(int i = n; i >= 1; i--){
            for(int j = m; j >= 1; j--){
                if (Dat[i][j] == 1 && Dat[i-1][j] == 0) Dat[i][j-1] = 1;
                if (Dat[i][j] == 1 && Dat[i][j-1] == 0) Dat[i-1][j] = 1;
            }
        }

        for(int i = n + m - 2; i >= 0; ){
            auto[a,b] = route[i];
            if(Dat[a][b] == 1) {
                i--;
                continue;
            }
            bool typeR = 0;
            if (route[i+1].x == a) typeR = 1;

            while(i >= 0){
                auto[a,b] = route[i];
                if(Dat[a][b] == 1) break;
                if (typeR){
                    R[a+b] = min(R[a+b], a - 1);
                }
                else{
                    L[a+b] = max(L[a+b], a+1);
                }
                i--;
            }

        }

        vector<pair<int, int>> result;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if (Dat[i][j] == 1) result.push_back(mp(i, j));
            }
        }

        if ((int)result.size() == n+m - 1){
            report();
            return;
        }

        for(int j = 1; j < (int)result.size(); j++){
            auto[a,b] =result[j-1];
            auto[c,d] =result[j];

            for(int ti = a; ti <= c; ti++){
                R[ti + b] = min(R[ti+b], ti);
            }
            for(int tj = b; tj <= d; tj++){
                R[c+tj] = min(R[c+tj], c);
            }

            for(int tj = b ; tj <= d;tj++){
                L[a+tj] = max(L[a+tj], a);
            }
            for(int ti = a; ti <= c; ti++){
                L[ti + d] = max(L[ti + d], ti);
            }
        }
        
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

