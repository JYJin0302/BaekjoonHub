#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


int V[11][4][4];
char C[11][4][4];

int n;
int cLst[4];
int ans = 0;
vector<pair<int, int>> offset = {mp(0, 0), mp(0, 1), mp(1, 0), mp(1, 1)};


int T[5][5];
char tC[5][5];

void apply(int ix, pair<int, int> os, int dir){
    if (dir == 0){
        for(int i = 0;i < 4; i++){
            for(int j = 0; j < 4; j++){
                int ni = i + os.x;
                int nj = j + os.y;

                T[ni][nj] += V[ix][i][j];
                T[ni][nj] = min(T[ni][nj], 9);
                T[ni][nj] = max(T[ni][nj], 0);
                if (C[ix][i][j] != 'W') tC[ni][nj] = C[ix][i][j];
            }
        }
    }
    else if (dir == 1){
        for(int i = 0;i < 4; i++){
            for(int j = 0; j < 4; j++){
                int ni = j + os.x;
                int nj = 3 - i + os.y;

                T[ni][nj] += V[ix][i][j];
                T[ni][nj] = min(T[ni][nj], 9);
                T[ni][nj] = max(T[ni][nj], 0);
                if (C[ix][i][j] != 'W') tC[ni][nj] = C[ix][i][j];
            }
        }
    }
    else if (dir == 2){
        for(int i = 0;i < 4; i++){
            for(int j = 0; j < 4; j++){
                int ni = 3 - i + os.x;
                int nj = 3 - j + os.y;

                T[ni][nj] += V[ix][i][j];
                T[ni][nj] = min(T[ni][nj], 9);
                T[ni][nj] = max(T[ni][nj], 0);
                if (C[ix][i][j] != 'W') tC[ni][nj] = C[ix][i][j];
            }
        }
    }
    else{
        for(int i = 0;i < 4; i++){
            for(int j = 0; j < 4; j++){
                int ni = 3 - j + os.x;
                int nj = i + os.y;

                T[ni][nj] += V[ix][i][j];
                T[ni][nj] = min(T[ni][nj], 9);
                T[ni][nj] = max(T[ni][nj], 0);
                if (C[ix][i][j] != 'W') tC[ni][nj] = C[ix][i][j];
            }
        }
    }

}

int getVal(){
    int res = 0;
    for(int i =0 ; i < 5; i++){
        for(int j =0 ; j <5; j++){
            if (tC[i][j] == 'R') res += T[i][j] * 7;
            else if (tC[i][j] == 'B') res += T[i][j] * 5;
            else if(tC[i][j] == 'G') res += T[i][j] * 3;
            else if(tC[i][j] == 'Y') res += T[i][j] * 2;
        }
    }

    return res;
}


void choose(int ix, int last = -1){
    if (ix == 3){

        vector<int> ord = {cLst[0], cLst[1], cLst[2]};
        do{
            for(auto f1 : offset){
                // 처음은 offset만 적용
                for(auto f2 : offset){
                    for(int d2 = 0; d2 < 4; d2++){

                        for(auto f3 : offset){
                            for(int d3 = 0; d3 < 4; d3++){
                                
                                memset(T, 0, sizeof T);
                                memset(tC, 'W', sizeof tC);

                                apply(ord[0], f1, 0);
                                apply(ord[1], f2, d2);
                                apply(ord[2], f3, d3);

                                int res = getVal();
                                ans = max(ans, res);
                            }
                        }
                    }
                }
            }


        }while(next_permutation(all(ord)));

        return;
    }

    for(int i = last + 1; i < n; i++){
        cLst[ix] = i;
        choose(ix+1, i);
    }

}

void solve(){
    
    cin >> n;
    for(int i = 0 ;i < n; i++){
        for(int a= 0 ;a  < 4; a++){
            for(int b= 0;b < 4; b++){
                cin >> V[i][a][b];
            }
        }
        for(int a= 0 ;a  < 4; a++){
            for(int b= 0;b < 4; b++){
                cin >> C[i][a][b];
            }
        }
    }


    choose(0);

    cout << ans << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
