#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int w, h;
    cin >> w >> h;

    int r;
    cin >> r;

    cout << setprecision(15);
    cout << w * h  - 0.25 * r * r * acos(-1) << '\n';

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