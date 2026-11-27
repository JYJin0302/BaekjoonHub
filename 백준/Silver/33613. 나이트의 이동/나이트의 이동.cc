#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    ll n;
    cin >> n;

    int r, c;
    cin >> r >> c;

    if (n == 3){
        if (r == 2 && c == 2) cout <<1 << '\n';
        else cout << 4 << '\n';
    }
    else{
        if (n % 2 == 0) cout << n*n/2 << '\n';
        else{
            if ((r + c) % 2 == 0){
                cout << n*n/ 2 + 1 << '\n';
            }
            else cout << n*n/2 << '\n';
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}