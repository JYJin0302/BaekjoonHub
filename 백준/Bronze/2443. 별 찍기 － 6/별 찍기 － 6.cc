#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        string s1(n - i, ' ');
        string s(2*i - 1, '*');
        cout << s1 + s << '\n';
    }

}