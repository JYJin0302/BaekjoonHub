#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int x, y;
    cin >> x >> y;

    int ans = 0;
    if (x == 0 || y == 0){
        ans = abs(x) + abs(y);
    }
    else{
        if (x > 0 && y > 0) ans = x + y;
        else if (x > 0 && y < 0){
            if (abs(y) <= x) ans = x;
            else ans = abs(y);
        }
        else if (x < 0 && y > 0 ){
            if (abs(x) <= y) ans = y;
            else ans = abs(x);
        }
        else if (x < 0 &&y < 0){
            ans = -x - y;
        }
    }
    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}