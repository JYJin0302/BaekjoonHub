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
    cin >> s;

    bool type = 0;

    vector<string> token;
    string tmp;
    for(auto f : s){
        if (isdigit(f)) tmp += f;
        else{
            token.push_back(tmp);
            tmp = "";
            if (f == '/') type = 1;
        }
    }
    token.push_back(tmp);

    while(token[0].size() < 2){
        token[0] = '0' + token[0];
    }
    while(token[1].size() < 2){
        token[1] = '0' + token[1];
    }
    while(token[2].size() < 4){
        token[2] = '0' + token[2];
    }
    

    if (type) swap(token[0], token[1]);
    cout << token[0] << '.' << token[1] << '.' << token[2] << ' ';
    cout << token[1] << '/' << token[0] << '/' << token[2] << '\n';


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
