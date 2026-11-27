#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

char G[1010][1010];
string tar = "KUMOH";
string tar2 = "HOMUK";

int cnt(string s){
    int n = (int)s.size();

    int c1 = 0, c2 = 0;
    for(int i = 0; i < n-4; i++){
        bool ok = 1;
        for(int j = 0; j <5; j++){
            if (tar[j] == s[i+j]) {}
            else ok = 0;
        }
        if (ok) c1++;
    }
    for(int i = 0; i < n-4; i++){
        bool ok = 1;
        for(int j = 0; j <5; j++){
            if (tar2[j] == s[i+j]) {}
            else ok = 0;
        }
        if (ok) c2++;
    }
    return max(c1, c2);
}

void solve() {

    int n;
    cin >> n;

    memset(G, '.', sizeof G);
    for(int i = 0 ;i < n ;i++){
        string s;
        cin >> s;

        for(int j = 0; j <(int)s.size(); j++){
            G[i][j] = s[j];
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        string tmp;
        int sx = i, sy = 0;

        while(sx >= 0 && sy < 1000){
            if(G[sx][sy] != '.') tmp += G[sx][sy];
            sx--, sy++;
        }
        ans += cnt(tmp);
    }

    for(int j = 1; j < 1000; j++){
        string tmp;
        int sx = n-1, sy = j;

        while(sx >= 0 && sy < 1000){
            if(G[sx][sy] != '.') tmp += G[sx][sy];
            sx--, sy++;
        }
        ans += cnt(tmp);
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}