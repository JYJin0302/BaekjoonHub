#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

void solve(){
    
    string s;
    getline(cin, s);

    string ts = "UCPC";
    int ix = 0;
    for(auto f : s){
        if (ix < 4 && f == ts[ix]) ix++;
    }
    if (ix == 4){
        cout << "I love UCPC\n";
    }
    else cout << "I hate UCPC\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
