#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()




void solve(){
    
    int n, m, k;
    cin >> n >> m >> k;

    if (n >= m){
        cout << 1 << '\n';
        return;
    }

    if (n == 1){
        cout << 2 << '\n';
    }
    else if (n == 2){
        if (n + 1 == k) cout << 4 << '\n';
        else cout << 3 << '\n';
    }
    else {
        cout << 5 << '\n';
    }
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