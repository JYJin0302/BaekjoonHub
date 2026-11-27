#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(s == string(n, '.')){
        if (n == 1) cout << "alice\n";
        else cout << "bob\n";
        return;
    }
    int res = 0;

    bool turn = 0;
    if (s[0] == '.' && s[1] == '.') {
        res++;
        s[0] = 'a';
        turn = 1;
    }
    else if(s[n-1] == '.' && s[n-2] == '.'){
        res++;
        s[n-1] = 'a';
        turn = 1;
    }

    if(turn){
        if (s[0] == '.' && s[1] == '.') {
            res--;
            s[0] = 'b';
        }
        else if(s[n-1] == '.' &&s[n-2] == '.'){
            res--;
            s[n-1] = 'b';
        }
    }

    if(s[0] == '.' && s[1] != '.'){
        if(s[1] == 'a') res--;
        else res++;
    }
    if(s[n-1] == '.' && s[n-2] != '.'){
        if (s[n-2] == 'a') res--;
        else res++;
    }

    int ix= 0;
    while(ix < n){
        char c = s[ix];
        if(ix == n-1) break;
        int nx = ix + 1;
        while(nx < n && s[nx] == '.') nx++;

        if (s[ix] != s[nx]) {}
        else if(s[ix] == 'a') res--;
        else res++;
        ix = nx;
    }

    if (res > 0) cout << "alice\n";
    else cout << "bob\n";
}

int main(){ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t-- ) solve();
    return 0;
}