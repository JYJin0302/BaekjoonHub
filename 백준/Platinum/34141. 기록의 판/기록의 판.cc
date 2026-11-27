#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int G[2020][2020];
int nxt[2020][10];

int n;
int len;
string cur;
string tmp;
bool goSet(int cdx = 0, int ix = 0, bool match = 1){

    //cout << "Goset: " << cdx << ' ' << ix << ' ' << match << ' ' << tmp << '\n';
    if (ix > n) return 0;
    if (len - cdx > n - ix) return 0;

    if (cdx == len) return !match;

    // cdx : cur에서의 index, ix : grid에서의 index
    if (match){
        int val = cur[cdx] - '0';
        for(int j = val; j >= 1; j--){
            tmp[cdx] = char('0' + j);
            int nx = nxt[ix+1][j];
            if(j == val){
                if (goSet(cdx+1, nx, 1)) return 1;
            }
            else{
                if (goSet(cdx+1, nx, 0)) return 1;
            }
        }
        tmp[cdx] = '?';
    }
    else{
        for(int j = 9; j >= 1; j--){
            tmp[cdx] = char('0' + j);
            int nx = nxt[ix+1][j];
            if (goSet(cdx+1, nx, 0)) return 1;
        }
        tmp[cdx] = '?';
    }
    return 0;
}

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j =1 ; j <= n; j++){
            char c;
            cin >> c;
            G[i][j] = c - '0';
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        cur += char('0'+ G[n][i]);
    }

    for(int i = n-1; i >= 1; i--){
        int nd = n - (int)cur.size();

       // cout << "NXT AR\n";
        for(int j = n; j >= 1; j--){
            if (j == n){
                for(int f = 1; f <= 9; f++) nxt[j][f] = n+1;
            }
            else {
                for(int f = 1; f <= 9; f++) nxt[j][f] = nxt[j+1][f];
            }
            nxt[j][G[i][j]] = j;
            
            //for(int  f= 1; f <= 9; f++) cout << nxt[j][f] << ' ';
            //cout << '\n';
        }

        len = (int)cur.size();
        tmp = string(len, '?');
        // nd개 사용 -> 같은 자리수, 작은 숫자
        
        bool test1 = goSet();
        if (test1){
           // cout << tmp << '\n';
            cur = tmp;
        }
        else{
            goSet(1, 0, 0);

            tmp = tmp.substr(1, len-1);
           // cout << tmp << '\n';
            cur = tmp;
        }

        ans += n - (int)tmp.size();
    }
    cout << ans << '\n';

    

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}