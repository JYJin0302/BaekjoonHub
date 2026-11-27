#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string ss;
    cin >> ss;

    int b = 0, s = 0;
    int ix = 0;
    while (ix < ss.size()) {

        if (ss[ix] == 's') s++, ix += 8;
        else b++, ix += 7;
    }

    if (b > s) cout << "bigdata?";
    else if (s > b) cout << "security!";
    else cout << "bigdata? security!";
}