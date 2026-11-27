#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    string s, t;
    cin >> s>> t;

    int h = 0, v =0;
    for(auto f :t){
        if (f == 'h'){
            h ^= 1;
        }
        else if (f == 'v'){
            v ^= 1;
        }
        else{
            h ^= 1;
            v ^= 1;
        }
    }

    if (h){
        reverse(all(s));
        for(auto& i : s){
            if (i == 'b' || i == 'd') i = char('b' + 'd' - i);
            else i = char('p' + 'q' - i);
        }
    }
    if(v){
        for(auto& i : s){
            if (i == 'b' || i == 'p') i = char('b' + 'p' - i);
            else i = char('d' + 'q' - i);
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
