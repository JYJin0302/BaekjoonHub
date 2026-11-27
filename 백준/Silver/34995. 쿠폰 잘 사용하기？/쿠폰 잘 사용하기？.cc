#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    string tar;
    cin >> tar;
    if ((int)s.size() < (int)tar.size()){
        cout << -1 << '\n';
        return;
    }

    for(auto& f : s) if (f == '?') f = '9';
    if((int)s.size() > (int)tar.size()){
        cout << s << '\n';
        return;
    }

    // compair
    for(int i =0 ; i < n; i++){
        if (s[i] > tar[i]) {
            cout << s << '\n';
            return;
        }
        else if (s[i] < tar[i]){
            cout << -1 << '\n';
            return;
        }
    }
    cout << s << '\n';

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