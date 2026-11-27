#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    while (n != 1 && m != 1) {
        n >>= 1, m >>= 1;
    }


    if (s[0] == 'V') {
        if (n > 1) cout << "Vicky can win\n";
        else cout << "Vicky cannot win\n";
    }
    else {
        if (m > 1) cout << "Harry can win\n";
        else cout << "Harry cannot win\n";
    }

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}