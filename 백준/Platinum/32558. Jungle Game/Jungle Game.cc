#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

bool used[202020][2];

void solve() {
 
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for(auto& i : A) cin >> i.x >> i.y;
    sort(all(A));
    
    for(auto f : A){
        used[f.x][0] = 1;
        used[f.y][1] = 1;
    }

    for(int i =2; i<= n*2; i += 2){
        if (!used[i][0]){
            cout << "YES\n";
            for(int j =0 ;j < n;j++){
                cout << i/2 << ' ' << j+1 << '\n';
            }
            return;
        }
        if (!used[i][1]){
            cout << "YES\n";
            for(int j =0 ;j < n;j++){
                cout << j+1 << ' ' << i/2 << '\n';
            }
            return;
        }
    }

    if (n == 1){
        cout << "NO\n";
        return;
    }

    int val = A[n-1].y;
    vector<int> ans(n+1, val/2);
    if (ans[n] == 1) ans[n]++;
    else ans[n]--;
    cout << "YES\n";
    for(int i =1;i <= n; i++){
        cout << i << ' ' << ans[i] << '\n';
    }
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