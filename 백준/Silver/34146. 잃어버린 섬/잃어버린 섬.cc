#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int cnt[101010];

void solve() {

    int n, m;
    cin >> n >> m;

    bool ok = 1;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            cnt[x]++;
        }
    }

    int cc = 0;
    
    for(int i = 1; i  <= 10000; i++){
        cc += cnt[i] / 2;
    }

    int lim = n * (m / 2);

    if (cc >= lim) cout <<"YES\n";
    else cout << "NO\n";
    
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