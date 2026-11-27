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

    vector<int> fail(n);
    int ix = 0;
    for(int i = 1; i < n; i++){
        while(ix && s[ix] != s[i]) ix = fail[ix-1];

        if(s[ix] == s[i]){
            ix++;
        }
        fail[i] = ix;
    }

    cout << n - fail[n-1] << '\n';
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
