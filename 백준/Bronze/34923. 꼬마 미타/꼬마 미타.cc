#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    string s1, s2;
    cin >> s1 >> s2;

    int v1 = 0, v2 = 0;
    v1 = ((s1[0]-'0') * 10 + (s1[1] - '0')) * 60 + (s1[3] - '0') * 10 + s1[4] - '0';
    v2 = ((s2[0]-'0') * 10 + (s2[1] - '0')) * 60 + (s2[3] - '0') * 10 + s2[4] - '0';

    //cout << v1 << ' ' << v2 << '\n';
    int ans = abs(v2 - v1);
    ans = min(ans, 12 * 60 - ans);
    cout << ans * 6 << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}