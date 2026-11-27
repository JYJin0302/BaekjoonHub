#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


char G[101][101];

void solve(){
    
    int n, m;
    cin >> n >> m;

    bool sw = 0;
    if (m % 5) {
        swap(n, m);
        sw = 1;
    }
    if (m % 5){
        cout << "no\n";
        return;
    }

    if (n == 1){
        if (m != 5) {
            cout << "no\n";
            return;
        }

        for(int j = 0; j < m; j++){
            G[0][j] = 'I';
        }
    }
    else if (n == 2){
        if (m == 5){
            cout << "no\n";
            return;
        }

        int i1 = 0, i2 = 0;
        for(int j =0; j < 2 * m/5; j++){
            if(j == 0){
                G[0][0] = G[0][1] = G[1][0] = G[1][1] = G[1][2] = 'P';
                i1 = 2;
                i2 = 3;
            }
            else if (j == 2 * m/5 - 1){
                while(i1 < m) G[0][i1++] = 'P';
                while(i2 < m) G[1][i2++] = 'P';
            }
            else{
                if (j & 1){
                    if (i1 < i2){
                        G[0][i1] = G[0][i1+1] = 'N';
                        G[1][i2] = G[1][i2+1] = G[1][i2+2] = 'N';

                        i1 += 2;
                        i2 += 3;
                    }
                    else{
                        G[0][i1] = G[0][i1+1] = G[0][i1+2] = 'N';
                        G[1][i2] = G[1][i2+1] = 'N';

                        i1 += 3;
                        i2 += 2;
                    }
                }
                else{
                    if (i1 < i2){
                        G[0][i1] = G[0][i1+1] = G[0][i1+2] = G[0][i1+3] = 'Y';
                        G[1][i2] = 'Y';

                        i1 += 4;
                        i2 += 1;
                    }
                    else{
                        G[0][i1] = 'Y';
                        G[1][i2] = G[1][i2+1] = G[1][i2+2] = G[1][i2+3] = 'Y';

                        i1 += 1;
                        i2 += 4;
                    }
                }
            }
        }
    }
    else if (n == 5){
        vector<string> B = {
            "VVVNN",
            "VNNNY",
            "VPUUY",
            "PPUYY",
            "PPUUY"
        };

        for(int i = 0; i < n;i++){
            for(int j= 0; j < m; j++){
                G[i][j] = B[i][j%5];
            }
        }
    }
    else{
        int tn = n;

        vector<string> B4 = {
            "IIIIIVPPUU",
            "VPPUUVPPPU",
            "VPPPUVVVUU",
            "VVVUUIIIII"
        };

        int ix = 0;
        while(tn % 3){
            // use 4
            for(int i = 0; i < 4; i++){
                for(int j =0 ; j < m; j++){
                    G[i+ix][j] = B4[i][j%10];
                }
            }
            tn -= 4;
            ix += 4;
        }

        vector<string> B3 = {
            "UUPPV",
            "UPPPV",
            "UUVVV",
            "VPPUU",
            "VPPPU",
            "VVVUU"
        };

        for(int i =0; i + ix < n; i++){
            for(int j =0; j < m; j++){
                G[i+ix][j] = B3[i%6][j%5];
            }
        }
    }

    cout << "yes\n";
    if(sw){
        for(int i =0 ;i < m; i++){
            for(int j =0 ; j < n;j++){
                cout << G[j][i];
            }
            cout << '\n';
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j =0 ; j< m; j++){
                cout << G[i][j];
            }
            cout << '\n';
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
