#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int Grid[2020][2020];
int Tgrid[2020][2020];
int cnt[2020][2][3]; // count of 0, 1, 2 : 0 = row, 1 = col
bool used[2020][2];


void solve(){

    int n;
    cin >> n;
    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ;j < n ;j++){
            int val;
            cin>> val;
            Grid[i][j] = val;

            cnt[i][0][val]++;
            cnt[j][1][val]++;
        }
    }

    // row
    vector<array<int, 3>> ans;
    queue<array<int, 3>> q;
    for(int i =0 ; i < n;i++){
        if (cnt[i][0][0]) continue;
        if (cnt[i][0][1] == n) q.push({i, 0, 1}), used[i][0] = 1;
        if (cnt[i][0][2] == n) q.push({i, 0, 2}), used[i][0] = 1;
    }
    for(int j =0 ;j < n; j++){
        if (cnt[j][1][0]) continue;
        if (cnt[j][1][1] == n) q.push({j, 1, 1}), used[j][1] = 1;
        if (cnt[j][1][2] == n) q.push({j, 1, 2}), used[j][1] = 1;
    }


    while(!q.empty()){
        auto f = q.front(); q.pop();
        ans.push_back(f);

        if (f[1] == 0){
            for(int j = 0; j < n; j++){
                if (used[j][1]) continue;
                if (f[2] == 2) cnt[j][1][1]++;
                else cnt[j][1][2]++;

                if (cnt[j][1][1] == n) q.push({j, 1, 1}), used[j][1] = 1;
                else if (cnt[j][1][2] == n) q.push({j, 1, 2}), used[j][1] = 1;
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if (used[i][0]) continue;
                if (f[2] == 2) cnt[i][0][1]++;
                else cnt[i][0][2]++;

                if (cnt[i][0][1] == n) q.push({i, 0, 1}), used[i][0] = 1;
                else if (cnt[i][0][2] == n) q.push({i, 0, 2}), used[i][0] = 1;
            }
        }
    }

    reverse(all(ans));
    for(auto f : ans){
        if (f[1] == 0){
            for(int j = 0; j < n; j++){
                Tgrid[f[0]][j] = f[2];
            }
        }
        else {
            for(int i = 0; i < n;i++){
                Tgrid[i][f[0]] = f[2];
            }
        }
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n ;j++){
            if (Grid[i][j] == Tgrid[i][j]){}
            else{
                cout << -1 << '\n';
                return;
            }
        }
    }
    

    cout << ans.size() << '\n';
    for(auto f:  ans) cout << f[1] + 1 << ' ' << f[0] + 1 << ' ' << f[2] << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
