#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int cnt[202020][26];

void solve(){
    
    int n, m;
    cin >> n >> m;


    string s1, s2;
    cin >> s1 >> s2;

    for(int i =1; i <= n; i++){
        int v = s1[i-1] - 'a';
        for(int j = 0 ;j < 26; j++){
            cnt[i][j] = cnt[i-1][j] + (j == v ? 1 : 0);
        }
    }

    ll ans = 0;
    for(int i = 0; i < m ;i++){
        int v = s2[i] - 'a';
        ans += cnt[i + n - m + 1][v] - cnt[i][v];
    }
    cout << ans << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}