#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool ok[101010];
int cnt[2];

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    string target = "PAUL";

    for(auto c : target){
        cnt[0] = 0;
        cnt[1] = 0;
        if (c == 'P') cnt[1] = 1;

        vector<int> lst;
        for(int i = 0 ; i < n; i++){
            if (ok[i]) cnt[i&1]++;
            if(s[i] == c && cnt[(i&1)^1]) lst.push_back(i);
        }

        memset(ok, 0, sizeof ok);
        for(auto f : lst) ok[f] = 1;

        // for(int i = 0; i < n;i ++) cout << ok[i];
        // cout << '\n';
        if (c == 'L'){
            for(auto f : lst){
                if ((n-f) & 1){
                    cout << "YES\n";
                    return;
                }
            }
            cout << "NO\n";
            return;
        }
    }
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