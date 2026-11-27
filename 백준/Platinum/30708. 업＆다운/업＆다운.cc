#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int cnt[101010];
int dp[101010];

void solve(){
    
    int n;
    cin >> n;
    
    int mn = 101010;
    int mx = -1;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        cnt[x]++;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    if (mn == mx){
        if (n == 1){
            cout << mn << '\n';
        }
        else cout << -1 << '\n';
        return;
    }
    
    for(int s : {mn, mn + 1}){
        for(int e : {mx-1, mx}){

            for(int j = mn; j <= mx; j++){
                dp[j] = cnt[j] - 1;
                if (mn + 1 <= j && j <= s) dp[j]--;
                if (e <= j && j <= mx - 1) dp[j]--;
            }

            bool ok = 1;
            for(int j = mn+1; j <= mx; j++){
                dp[j] -= dp[j-1];
                if (dp[j] < 0) ok = 0;
            }
            if (dp[mx] != 0) ok = 0;

            if (!ok) continue;

            // ans Found
            vector<int> res;
            for(int i = s; i >= mn; i--) {
                res.push_back(i);
                cnt[i]--;
            }
            for(int i = mn + 1; i <= mx; i++){
                res.push_back(i);
                cnt[i]--;

                while(cnt[i-1] && cnt[i]){
                    res.push_back(i-1);
                    cnt[i-1]--;
                    res.push_back(i);
                    cnt[i]--;
                }
            }
            for(int i = mx-1; i >= e; i--){
                res.push_back(i);
                cnt[i]--;
            }

            for(int i = mn; i <= mx; i++) assert(cnt[i] == 0);

            for(auto f : res) cout <<f << ' ';
            cout << '\n';
            return;
        }
    }
    
    cout << -1 << '\n';
    
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