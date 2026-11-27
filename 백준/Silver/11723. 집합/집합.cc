#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n, x;
    cin >> n;

    int base = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s == "add") {
            cin >> x;
            base |= (1 << (x - 1));
        }
        else if (s == "remove") {
            cin >> x;
            base &= ~(1 << (x - 1));
        }
        else if (s == "check") {
            cin >> x;
            cout << ((base & (1 << x - 1))>0) << '\n';
        }
        else if (s == "toggle") {
            cin >> x;
            base ^= (1 << (x - 1));
        }
        else if (s == "all") {
            base = (1<<20)-1;
        }
        else if (s == "empty") {
            base = 0;
        }
    }
}