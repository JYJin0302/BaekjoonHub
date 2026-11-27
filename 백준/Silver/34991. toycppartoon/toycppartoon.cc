#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    string s;
    cin >> s;

    string tar = "toycartoon";

    pair<int, int> res = mp(-1, -1);
    int n =s.size();
    for(int i = 0; i < n; i++){
        string pre = s.substr(0, i+1);
        
        int found = -1;
        for(int j =0 ;j < (int)tar.size(); j++){
            if (tar.substr(j, i+1) == pre){
                found = j;
                break;
            }
        }
        if (found != -1){
            res= mp(i, found);
        }
    }

    if (res.first == -1){
        string ans = tar + "_" + s;
        if (ans.size() > 20) ans = tar;
        cout << ans << '\n';
    }
    else{
        int ix1 = res.second;

        int len = res.first + 1;

        string T, Y;
        for(int i=0; i < ix1; i++) T += tar[i];

        for(int i= ix1 + len; i < (int)tar.size(); i++) Y += tar[i];

        string s2 = s.substr(len, 20);
        int len2 = 0;
        for(int i =0 ; i < (int)s2.size(); i++){
            if (s2.substr((int)s2.size() - 1 - i, i+1) == Y.substr(0, i+1)) len2 = i+1;
        }

        string ans = T + s;

        for(int i = len2; i < (int)Y.size(); i++) ans += Y[i];

        if (ans.size() >20 ) ans = tar;
        cout << ans << '\n';

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