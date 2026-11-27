#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> ans1(n), ans2(n);
    ans1[0] = 0;
    
    int mn = 0;
    int ix = 0;
    while(ix < n-1){
        int nx = ix;
        while(nx < n-1 && s[nx] == '<') nx++;

        int len = nx - ix;
        if (len == 0){
            ans1[ix+1] = mn - 1;
            ix++;
            mn--;
        }
        else{
            ans1[ix] = mn - len;
            for(int i = ix; i < nx; i++){
                ans1[i+1] = ans1[i] + 1;
            }
            mn -= len;
            ix = nx;
        }
    }

    for(auto& i : ans1) i -= mn - 1;

    int cc = 0, nn = 0;;
    ans2[0] = 0;
    for(int i =0; i< n-1; i++){
        if (s[i] == '<'){
            ans2[i+1] = ++cc;
        }
        else ans2[i+1] = --nn;
    }

    for(auto &f : ans2) f -= nn - 1;


    for(auto f :ans1) cout << f<< ' ';
    cout << '\n';

    
    for(auto f :ans2) cout << f<< ' ';
    cout << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
