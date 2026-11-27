#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    string s;

    vector<string> p1, p2;
    bool part2 = 0;
    while(getline(cin, s)){
        if ((int)s.size() >= 2 && s[0] == '\\' && s[1] == 'b'){
            part2 = 1;
        }
        if (part2) p2.push_back(s);
        else p1.push_back(s);
    }

    map<string, int> ord;

    int o = 0;
    for(auto f : p1){
        int ix = 0;
        while(ix < (int)f.size()){
            if (f[ix] == '\\'){
                ix += 6;
                string tmp;
                while(f[ix] != '}') {
                    tmp += f[ix];
                    ix++;
                }
                ord[tmp] = o++;
            }
            else ix++;
        }
    }

    // for(auto [a,b]: ord) cout << a<< ' '<< b << " | ";
    // cout << '\n';


    int s2 = (int)p2.size();
    bool ok = 1;

    vector<pair<int, string>> B;
    for(int i = 1; i < s2-1; i++){
        int ix = 0;
        while(p2[i][ix] != '{') ix++;
        ix++;

        string tt;
        while(p2[i][ix] != '}') {
            tt += p2[i][ix];
            ix++;
        }

        B.push_back(mp(ord[tt], p2[i]));
    }
    sort(all(B));
    //for(auto[a,b]:  B) cout << a << ' ' << b << '\n';

    for(int i =1; i < s2-1; i++){
        if (B[i-1].y != p2[i]) ok = 0;
        p2[i] = B[i-1].y;
    }

    if (ok){
        cout << "Correct\n";
        return;
    }
    cout << "Incorrect\n";
    for(auto f : p2) cout << f<< '\n';


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
