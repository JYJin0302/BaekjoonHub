#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> tmp[6];
int out[222];

void solve() {

    int n;
    cin >> n;

    vector<int> ans;
    for(int i =1; i <= n; i++) ans.push_back(i);

    while((int)ans.size() != 1){

        for(int j = 0; j <= 5;j ++) tmp[j].clear();

        int tot = 0;
        memset(out, 0 ,sizeof out);
        for(int j = 0 ;j < (int)ans.size(); j++){
            tmp[j%6].push_back(ans[j]);
            out[ans[j]] = j % 6;
            tot += 9 * (j % 6);
        }

        cout << "? ";
        for(int i = 1;i <= n;i++) cout << out[i]<< ' ';
        cout << endl;

        int res;
        cin >> res;

        int dif = res - tot;
        ans.clear();
        ans = tmp[dif];
    }
    cout << "! " << ans[0] << endl;


}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}