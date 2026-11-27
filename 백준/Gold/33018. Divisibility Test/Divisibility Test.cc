#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mp make_pair
void solve(){
    
    ll b, n;
    cin >> b >> n;


    ll res1 = -1, res2 = -1, res3 = -1;

    int step = 1;
    ll res = ((-b) % n + n) % n;
    vector<bool> vis(n);
    while(1){
       // cout << "S3: " << res << ' ' << step << endl;
        if (res == 1){
            res3 = step;
            break;
        }
        if (vis[res]) break;
        vis[res] = 1;
        res = res * b % n;
        step++;
    }

    step = 1;
    res = b % n;

    vis = vector<bool>(n);
    while(1){
        //cout << "S3 " << res << ' '<<step << endl;
        if (res == 0){
            res1 = step;
            break;
        }
        if (vis[res]) break;
        vis[res] = 1;
        res = res * b % n;
        step++;
    }

    vis = vector<bool>(n);
    step = 1;
    res = b % n;
    while(1){
        if (res == 1){
            res2 = step;
            break;
        }
        if (vis[res]) break;
        vis[res] = 1;
        res = res * b % n;
        step++;
    }

    vector<pair<int, int>> ans;
    if (res1 != -1) ans.push_back(mp(res1, 1));
    if (res2 != -1) ans.push_back(mp(res2, 2));
    if (res3 != -1) ans.push_back(mp(res3, 3));
    sort(ans.begin(), ans.end());
    if (ans.empty()){
        cout << 0 << '\n';
    }
    else{
        cout << ans[0].second << ' ' << ans[0].first << '\n';
    }


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}