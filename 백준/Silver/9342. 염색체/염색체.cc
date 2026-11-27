#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

#define NO cout << "Good\n"; return;
#define YES cout << "Infected!\n"; return;

void solve() {

    string s;
    cin >> s;
    
    int n = s.size();
    int ix = 0;
    
    if (s[0] >= 'B' && s[0] <= 'F') ix++;

    if (ix == n || s[ix] != 'A') {
        NO
    }
    while(ix < n && s[ix] == 'A') ix++;
    if (ix == n || s[ix] != 'F') {
        NO
    }

    while (ix < n && s[ix] == 'F') ix++;
    if (ix == n || s[ix] != 'C') {
        NO
    }

    while (ix < n && s[ix] == 'C') ix++;

    if (ix < n && s[ix] >= 'A' && s[ix] <= 'F') ix++;

    if (ix == n) {
        YES
    }
    else NO

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}