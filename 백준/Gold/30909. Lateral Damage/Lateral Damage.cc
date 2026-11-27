#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
using ld= long double;
#define mp make_pair

int res[101][101];
int n, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inGrid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int query(int i, int j){
    if (res[i][j] != 0) return res[i][j];
    cout << i << ' ' << j << endl;
    string s;
    cin >> s;

    if (s == "sunk") {
        k--;
        if (k == 0) exit(0);
        return res[i][j] = 1;
    }
    if (s[0] == 'h') {
        return res[i][j] = 1;
    }
    return res[i][j] = -1;
}
void solve(){
    
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if ((i + j) % 5 == 4){
                query(i+1, j+1);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if ((i + j) % 5 == 4 && res[i+1][j+1] == 1){
                int a= i+1, b = j+1;
                for(int d = 0;d < 4; d++){
                    int cnt = 5;
                    int na = a + dx[d];
                    int nb = b + dy[d];
                    while(cnt-- && inGrid(na, nb) && query(na, nb) == 1){
                        na += dx[d];
                        nb += dy[d];
                    }
                }
            }
        }
    }

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}