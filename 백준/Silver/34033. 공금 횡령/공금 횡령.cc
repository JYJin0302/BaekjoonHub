#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n, m;
    cin >> n >> m;

    map<string, int> cost;
    for(int i =0 ; i < n;i++){
        string s;
        cin >> s;
        int c;
        cin >> c;
        cost[s] = c;
    }

    int ans = 0;
    for(int i =0 ; i < m; i++){
        string s;
        cin >> s;
        int c;
        cin >> c;

        int tc = floor(cost[s] * 105 / 100);
        if (c > tc){
            ans++;
        }

    }
    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}