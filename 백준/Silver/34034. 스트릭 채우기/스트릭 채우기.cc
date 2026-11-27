#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> D(n);
    for(int i = 0; i < n; i++){
        cin >> D[i].x;
        D[i].y = i;
    }
    sort(all(D));

    vector<int> ans(k + 210000);

    int tot = 0;
    int need = 0;
    for(auto f : D){
        need += min(k - tot, f.x - 1);
        for(int i = 0; i < f.x; i++){
            ans[++tot] = 0;
        }
        ans[tot] = f.y + 1;
        if (tot >= k) break;
    }
    need += max(0, k - tot);

    if (need <= m){
        for(int i = 1; i <= k; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    else cout << -1 << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}