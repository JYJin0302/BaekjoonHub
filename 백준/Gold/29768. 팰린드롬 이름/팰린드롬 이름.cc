#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n, m;
    cin >> n >> m;

    n -= m - 1;
    
    cout << string(n, 'a');
    for (int j = 1; j < m; j++) cout << char('a' + j);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}