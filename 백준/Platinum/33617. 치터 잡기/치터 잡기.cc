#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    int n;
    cin >> n;

    vector<vector<int>> ans;

    int cx = 1, cy = 1;
    for(int i = 0; i < n - 1; i++){

        int tar = 0;
        int dx = 1;
        if (cx == 1) tar = n, dx = 1;
        else tar = 1, dx = -1;

        for(int j = 0; j < n; j++){
            bool up = 0;
            vector<int> res;
            for(int k = 0; k < n; k++){
                if (!up && cx == tar) {
                    up = 1;
                    if (j & 1) cy--;
                    else cy++;
                }
                else if (j & 1) cx -= dx;
                else cx += dx;
                res.push_back(cx), res.push_back(cy);
            }
            ans.push_back(res);
            tar -= dx;
        }

        if (n% 2 == 0){
            vector<int> res;
            cy++;
            res.push_back(cx), res.push_back(cy);
            for(int i = 1; i < n;i++){
                cx += dx;
                res.push_back(cx), res.push_back(cy);
            }
            ans.push_back(res);
        }            
    }

    cout << ans.size() << '\n';
    cout << 1 << ' '<< 1 << '\n';
    for(auto v : ans){
        cout << v.size() / 2  << ' ';
        for(auto f : v) cout << f<< ' ';
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
