#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    ll H, S;
    cin >> H >> S;

    if (H <= 2) {
        cout << 1 << '\n';
        return;
    }

    if (H <= 4){
        cout << 2 + S << '\n';
        return;
    }

    H += 3 * S;

    cout << (H+1)/ 2 << '\n';
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