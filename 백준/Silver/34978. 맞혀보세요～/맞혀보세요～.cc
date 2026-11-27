#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool rule[30];
bool ok[33][33];

void solve(){
    
    int n;
    cin >> n;
    for(int i =0 ; i < n; i++){
        char c;
        cin >> c;
        int m;
        cin >> m;

        
        int c1 = c - 'a';
        rule[c1] = 1;

        while(m--){
            char c2;
            cin >> c2;

            int v2 = c2 - 'a';
            ok[c1][v2] = 1;
        }
    }

    string s;
    cin >> s;
    int sn = (int)s.size();
    for(int i = 1; i < sn ;i++){
        int v1 = s[i-1] - 'a';
        int v2 = s[i] - 'a';

        if (!rule[v1] || ok[v1][v2]){}
        else{
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
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