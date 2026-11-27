#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = {-1, 0, 1, 1, 0, -1};
int dy[] = {1, 1, 1, -1, -1, -1};

char G[5900][8800];

void solve(){

    int n;
    cin >> n;

    vector<int> lineSeg = {2, 4, 0}; // 방향
    for(int i =2; i <= n; i++){
        vector<int> tmp;
        for(auto f: lineSeg){
            tmp.push_back(f);
            tmp.push_back((f+5)%6);
            tmp.push_back((f+1)%6);
            tmp.push_back(f);
        }

        lineSeg = tmp;
    }


    vector<int> mx(6000);
    vector<pair<int, int>> ans;
    int x = 0, y = 0;
    for(auto f : lineSeg){
        if (f == 1 || f == 4){
            for(int j =0 ;j < 4; j++){
                x += dx[f];
                y += dy[f];
                ans.push_back(mp(x, y));
            }
        }
        else{
            for(int j =0 ;j < 2; j++){
                x += dx[f];
                y += dy[f];
                ans.push_back(mp(x, y));
            }
        }
    }

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for(auto[a,b] : ans){
        x1 = min(x1, a);
        y1 = min(y1, b);
        x2 = max(x2, a);
        y2 = max(y2, b);
    }

    memset(G, ' ', sizeof G);

    //cout << x1 << ' '<< y1 << ' ' << x2 << ' ' << y2 << '\n';
    for(auto[a,b] : ans){
        mx[a] = max(mx[a], b-y1);
        G[a-x1][b-y1] = '*';
    }

    for(int i = x1; i <= x2; i++){
        for(int j = 0; j <= mx[i]; j++){
            cout << G[i][j];
        }
        cout << '\n';
    }


}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}