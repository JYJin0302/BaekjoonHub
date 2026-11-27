#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

#define NO {cout << -1 << '\n'; return;}

char Grid[3030][3030];

void solve(){
    
    int n, m;cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> Grid[i][j];
    }

    for(int i = n; i >= 2; i--){
        int len = 0;
        for(int j = 1; j <= m; j++){
            //cout << "Go: " << i << ' ' << j << ' ' << len << '\n';
            if(Grid[i][j] == '.'){
                len++;
                if (len == 2){
                    // upper row inspect
                    int tj = j;
                    while(tj && Grid[i-1][tj] == '.') tj--;
                    int tlen = j - tj;
                    if (tlen % 2 == 0){
                        if(Grid[i-1][j-1] == '.'){
                            Grid[i][j] = 'a';
                            Grid[i][j-1] = 'a';
                            Grid[i-1][j-1] = 'a';
                        }
                        else NO;
                    }
                    else{
                        if (Grid[i-1][j] == '.') {
                            Grid[i][j] = 'b';
                            Grid[i][j-1] = 'b';
                            Grid[i-1][j] = 'b';
                        } 
                        else NO;
                    }
                    len = 0;
                }
            }
            else{
                if (len) NO;
            }
        }

        if (len) NO;
    }

    for(int i = 1; i <= m; i++){
        if (Grid[1][i] == '.') NO;
    }

    for(int i =1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << Grid[i][j];
        }
        cout << '\n';
    }


}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}