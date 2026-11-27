#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 998244353;

ll pw2[101010];

void solve() {
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n+1);
    for(int i= 1; i <= n; i++) cin >> A[i];

    vector<int> B(n+10);
    for(int i =0  ;i < k; i++){
        int a, b;
        cin >> a >> b;
        B[a]++;
        B[b+1]--;
    }

    for(int i =1; i <= n; i++) B[i] += B[i-1];

    pw2[0] = 1;
    for(int i = 1; i <= 100010; i++) pw2[i] = pw2[i-1] * 2 % mod;

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int cnt = B[i];
        ll mul = pw2[k - cnt];
        if (cnt == 0){
            if (A[i]) ans = (ans + mul) % mod;
            continue;
        }
        ll val = pw2[cnt-1];
        ans = (ans + val * mul % mod) % mod;
    }
    cout << ans << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}