#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ix1, ix2;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') ix1.push_back(i);
        if (s[i] == 'C') ix2.push_back(i);
    }

    for (int i = 0; i < min(ix1.size(), ix2.size()); i++) {
        swap(s[ix1[i]], s[ix2[i]]);
    }

    cout << s;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}