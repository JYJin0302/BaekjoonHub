#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, k;
int G[10][10];
int P[10];
int ans = 0;
int track[10];

int tG[10][10];
int tCur[10][10];

int dx [] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void goSimul(){
    for(int i = 0; i < n;i++){
        for(int j =0;j < n;j++){
            tG[i][j] = tCur[i][j] = G[i][j];
        }
    }

    int score = 0;
    for(int i = 0; i < k;i++){
        int row = track[i];
        int pw = P[i];
        // shoot row

        for(int j =0 ; j < n; j++){
            if (tCur[row][j]){
                bool bonus = tG[row][j] >= 10;
                if (bonus) {
                    score += tG[row][j];
                    tCur[row][j] = tG[row][j] = 0;
                    break;
                }
                tCur[row][j] = max(0, tCur[row][j] - pw);
                if (tCur[row][j] == 0){
                    score += tG[row][j];

                    for(int k =0 ; k < 4; k++){
                        int na = row + dx[k];
                        int nb = j + dy[k];

                        if (na >= 0 && na < n &&nb >= 0 && nb < n && tCur[na][nb] == 0){
                            tG[na][nb] = tCur[na][nb] = tG[row][j] / 4;
                        }
                    }
                    tG[row][j] = 0;
                }
                break;
            }
        }
    }
    ans = max(ans, score);


}

void choose(int ix){
    if (ix == k){
        goSimul();
        return;
    }
    for(int i = 0; i < n; i++){
        track[ix] = i;
        choose(ix+1);
    }
}


void solve(){
    cin >> n >> k;
    for(int i =0 ; i < n;i++){
    for(int j =0 ; j < n;j++){
        cin >> G[i][j];
    }}

    for(int i =0 ; i < k;i++){
        cin >> P[i];
    }

    choose(0);
    cout << ans << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}