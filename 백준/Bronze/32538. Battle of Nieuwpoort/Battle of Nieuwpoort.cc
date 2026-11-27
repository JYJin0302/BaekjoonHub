#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve(){
    
    int x;
    cin >> x;

    string s;
    cin >> s >> s >> s;

    for(int b = 2; b <= 16; b++){
        if (x % (b*b) == 0){
            cout << b << ' ';

            string res;
            while(x){
                int v = x % b;
                if (v <= 9) res += char('0' + v);
                else res += char('a' + v - 10);
                x /= b;
            }
            reverse(all(res));
            cout << res << '\n';
            return;
        }
    }
    cout << "impossible\n";

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}