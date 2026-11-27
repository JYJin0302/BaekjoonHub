#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1(n - 1 - i, ' ');
        string s(i + 1, '*');
        cout << s1 + s << '\n';
    }
    for (int i = n - 2; i >= 0; i--) {
        string s1(n - 1 - i, ' ');
        string s(i + 1, '*');
        cout << s1 + s << '\n';
    }

}