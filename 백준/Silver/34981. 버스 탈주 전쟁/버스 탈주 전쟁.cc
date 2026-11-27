#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int X, Y;
    cin >> X >> Y;
    int n;
    cin >> n;

    vector<bool> rec(20000);

    for(int i =0;i < n; i++){
        int x, y, d;
        cin >> x>> y >> d;

        int v = x * 60 + y;
        while(v < 24 * 60){
            rec[v] = 1;
            v += d;
        }
    }

    int cur = X * 60 + Y;

    int ans = 0;
    while(!rec[cur]){
        cur = (cur + 1) % (24 * 60);
        ans++;
    }

    int tx = cur / 60;
    int ty = cur % 60;

    string s1 = to_string(tx);
    string s2 = to_string(ty);
    if ((int)s1.size() == 1) s1 = '0' + s1;
    if ((int)s2.size() == 1) s2 = '0' + s2;

    cout << s1 << ":" << s2 << '\n';
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