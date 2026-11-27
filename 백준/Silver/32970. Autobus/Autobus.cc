#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<array<int ,2>> rec[2];
void solve(){
    
    int n;
    cin >> n;

    for(int i =0 ; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;

        vector<int> T;
        int ix = 0;
        while(ix < (int)s2.size()){
            int val = 0;
            while(ix < (int)s2.size() && isdigit(s2[ix])){
                val = val * 10 + s2[ix] - '0';
                ix++;
            }
            T.push_back(val);
            while(ix < (int)s2.size() && !isdigit(s2[ix])){
                ix++;
            }
        }

        array<int, 2> tt = {T[0] * 60 + T[1], T[2]*60 + T[3]};
        if (tt[1] < tt[0]) tt[1] += 24*60;

        if (s1[0] == 'Z'){
            rec[0].push_back(tt);
          //  cout << "REc 0: " << tt[0] << ' ' << tt[1] << '\n';
        }
        else{
            rec[1].push_back(tt);
           // cout << "REc 1: " << tt[0] << ' ' << tt[1] << '\n';
        }
    }

    if (rec[0].empty() || rec[1].empty()){
        cout << "NEMOGUCE\n";
        return;
    }

    int ans = 10 * 24 * 60;
    for(auto f : rec[0]){
        for(auto v : rec[1]){
            while (v[0] <= f[1]){
                v[0] += 24*60;
                v[1] += 24*60;
            }
            ans = min(ans, v[1] - f[0] + 1);
        }
    }

    string h = to_string(ans / 60);
    string m = to_string(ans % 60);
    if ((int)m.size() == 1) m = '0' + m;

    cout << h << ":" << m << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
