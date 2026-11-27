#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    string s;
    cin >> s;
    int n = s.size();
    
    if (s[n-1] == '5'){
        cout << "0 5\n";
        return;
    }
    if (s[n-2] == '5'){
        cout << n << ' ' << 5 << '\n';
        return;
    }

    ll tot = 0;
    for(auto f : s){
        tot += f - '0';
    }
    if (tot % 3 == 0){
        cout << "0 3\n";
        return;
    }
    for(int i = 0; i < n; i++){
        int val = s[i] - '0';
        if (val % 3 == tot % 3){
            cout << i+1 << ' '<< 3 << '\n';
            return;
        }
    }

    if (n % 2 ==0) cout << "0 11\n";
    else cout << "1 11\n";


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}