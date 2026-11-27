#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int cnt[4];

void solve(){
    
    
    string s;
    cin >> s;
    int n = s.size();

    int ans = n;
    vector<int> ord(4);
    for(int i =0 ; i <4 ;i++) ord[i] = i;

    map<char, int> cx;
    string ts = "hdcs";
    for(int i =0 ;i < 4; i++) cx[ts[i]] = i;
    
    do{
        for(int i = 0; i < 4;i++) cnt[i] = 0;

        vector<pair<int, int>> res;
        for(int i = 0; i < n; i++){
            int od = ord[cx[s[i]]];
            res.push_back(mp(od, cnt[od]));
            cnt[od]++;
        }

        vector<pair<int, int>> num;
        for(auto f : res){
            int it = lower_bound(all(num), f) - num.begin();
            if (it == (int)num.size()) num.push_back(f);
            else num[it] = f;
        }

        ans = min(ans, n - (int)num.size());
    } while(next_permutation(all(ord)));

    cout << ans << '\n';
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