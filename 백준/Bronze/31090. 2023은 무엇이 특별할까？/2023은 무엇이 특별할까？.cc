#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    if ((n + 1) % (n % 100) == 0) cout << "Good\n";
    else cout << "Bye\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}