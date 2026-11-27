#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

char G[55][55];

void solve(){
    
    int n, m;
    cin >> n >> m;

    int wallCnt = 0;
    int oneDir = 0;
    int allDir = 0;
    int vacc = 0;
    int s = 0,e = 0;


    for(int i =0 ; i < n; i++){
        for(int j =0 ; j < m; j++){
            char c;
            cin >> c;
            if (c == '.') {}
            else if (c == '#') wallCnt++;
            else if (c == 'U' || c == 'D' || c == 'R' || c == 'L') oneDir++;
            else if (c == 'A') allDir++;
            else if (c == 'S') s++;
            else if (c == 'E') e++;
            else if (c == 'V') vacc++;
        }
    }

    if (s != 1 || e != 1){
        cout << -1 << '\n';
        return;
    }

    if (vacc == 0 && allDir == 0 && wallCnt <= 1 && oneDir <= 1) cout << 1<< '\n';
    else if (vacc == 0 && allDir == 0) cout << 2 << '\n';
    else if (allDir == 0) cout << 3 << '\n';
    else cout << 4 << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}

