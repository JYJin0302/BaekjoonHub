#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pii;
#define mp make_pair

int ck[44][777];

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < 42; i++){
        for(int j = 0; j < 720; j++){
            ck[i][j] = 0;
        }
    }

    for(int i = 0; i <n; i++){
        char c;
        cin >> c;

        int x, y, z;
        cin >> x >>y >> z;

        x *= 2;
        y *= 2;
        z *= 2;

        if(c== 'C'){
            for(int s = y; s != z; s = (s+1) % 720){
                ck[x][s] = -1;
            }
        }
        else{
            for(int s = x; s <= y; s++){
                ck[s][z] = -1;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(mp(0, 0));
    while(!q.empty()){

        int a, b;
        tie(a, b) = q.front();
        q.pop();

        if(a > 40){
            cout <<"YES\n";
            return;
        }

        int nb =(b+1)% 720;
        if (ck[a][nb] == 0) {
            ck[a][nb] = 1;
            q.push(mp(a, nb));
        }

        nb = (b + 719) % 720;
        if (ck[a][nb] == 0) {
            ck[a][nb] = 1;
            q.push(mp(a, nb));
        }

        int na = a + 1;
        if(ck[na][b] == 0){
            ck[na][b] = 1;
            q.push(mp(na, b));
        }

        if(a >0){
            na = a - 1;
            if(ck[na][b] == 0){
                ck[na][b] = 1;
                q.push(mp(na, b));
            }
        }
    }
    cout <<"NO\n";

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int t=1;
    cin >>t;
    while(t--){
        solve();
    }
}
