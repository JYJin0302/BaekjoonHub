#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    ll x, y;
    cin >> x>> y;
    
    vector<pair<char, ll>> ans;

    while(x){
        string s = to_string(x);
        if (s[0] == '1'){
            int len = 0;
            while(len < (int)s.size() && s[len] == '1') len++;

            s = s.substr(len);
            ans.push_back(mp('-', len));
            if (s.empty()) s = "0";
            x = stoll(s);
            continue;
        }

        ll tar = 1;
        for(int i = 0; i < (int)s.size(); i++){
            tar *= 10;
        }

        ll rm = tar - x;
        rm = (rm + 8) / 9;

        ans.push_back(mp('+', rm));
        x += 9 * rm;
    }

    while(x != y){
        if (y >= x && (y - x) % 9 == 0){
            ll nn = (y- x)/ 9;
            ans.push_back(mp('+', nn));
            x  += nn * 9;
        }
        else {
            if (x >= 10) {
                x -= 10;
                ans.push_back(mp('-', 1));
            }
            else{
                x += 9;
                ans.push_back(mp('+', 1));
            }
        }
    }


    cout << "Stable\n";
    cout << (int)ans.size() << '\n';
    for(auto[a,b]: ans) cout << a<< ' '<< b << '\n';
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

