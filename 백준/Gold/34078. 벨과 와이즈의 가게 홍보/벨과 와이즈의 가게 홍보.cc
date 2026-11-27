#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


void solve(){

    int n;
    cin >> n;

    vector<int> A(n + 1);
    for(int i= 1; i <= n; i++) cin >> A[i];


    ll ans1 = 0, ans2 = 0;
    vector<bool> used(n+1);
    for(int i = 1; i <= n;i++){
        if (used[i] || A[i] == i) continue;
        int cur = i;
        int len = 0;
        while(1){
            cur = A[cur];
            used[cur] = 1;
            len++;
            if (cur == i) break;
        }
        ans1 += len - 1;
    }

    for(int i = 1; i <= n; i++) A[i] = n+1 - A[i];
    used = vector<bool>(n+1);
    for(int i = 1; i <= n;i++){
        if (used[i] || A[i] == i) continue;
        int cur = i;
        int len = 0;
        while(1){
            cur = A[cur];
            used[cur] = 1;
            len++;
            if (cur == i) break;
        }
        ans2 += len - 1;
    }


    //cout << ans1 << ' ' << ans2 << '\n';
    cout << n-2 << ' ' << min(ans1, ans2) << '\n';

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