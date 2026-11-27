#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
 
int root[4040];
int sz[4040];
int find(int n){
    if (root[n] == n)return n;
    return root[n] = find(root[n]);
}
 
int dp[4040][4040];
 
void solve() {
 
    int n;
    cin >> n;
    vector<int> A(2*n);
    for(auto& i : A) cin >> i;
 
    sort(all(A));
 
    for(int i = 0; i < n*2; i++){
        root[i] = i;
        sz[i] = 1;
    }
 
    for(int i = 1; i < n*2; i++){
        for(int j = 0; j < i ;j++){
            int v= A[i] ^A[j];
 
            if (__builtin_popcount(v) == 1){
                int ti = find(i);
                int tj = find(j);
                if (ti != tj){
                    root[tj] = ti;
                    sz[ti] += sz[tj];
                }
            }
        }
    }
 
    // for(auto f : A) cout << f<< ' ';
    // cout << '\n';
    // for(int i = 0; i < n*2; i++) cout << find(i) << ' ';
    // cout << '\n';
 
    vector<pair<int, int>> T;
    for(int i =0 ; i < n*2; i++){
        if(find(i) == i){
            T.push_back(mp(sz[i], i));
        }
    }
 
    dp[0][0] = 1;
    int sn = (int)T.size();
    for(int i = 1; i <= sn; i++){
        int s = T[i-1].x;
        for(int j = 0; j <= n*2; j++){
            dp[i][j] = dp[i-1][j];
            if (j >= s && dp[i-1][j-s]) dp[i][j] = 1;
        }
    }
 
    if(!dp[sn][n]){
        cout << -1 << '\n';
        return;
    }
 
    vector<int> pos(n*2, -1);
    int cur = n;
    for(int j = sn; j; j--){
        int s = T[j-1].x;
        int g = T[j-1].y;
        if(cur-s >= 0 && dp[j-1][cur-s]){
            cur -= s;
            pos[g] = 0;
        }
        else {
            pos[g] = 1;
        }
    }
 
    vector<int> L, R;
    for(int i = 0; i < n*2; i++){
        int fi = find(i);
        if(pos[fi] == 0) L.push_back(A[i]);
        else R.push_back(A[i]);
    }
 
    if ((int)L.size() != (int)R.size()){
        cout  << "??\n";
    }
    for(auto f : L) cout <<f  << ' ';
    cout << '\n';
    for(auto f : R) cout <<f  << ' ';
    cout << '\n';
 
 
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
