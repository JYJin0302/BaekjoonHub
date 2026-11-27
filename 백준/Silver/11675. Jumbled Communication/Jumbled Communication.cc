#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


int A[303];
void solve() {

    for (int i = 0; i < 256; i++) {
        int ni = (i << 1) ^ i;
        ni %= 256;

        A[ni] = i;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << A[x] << ' ';
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}