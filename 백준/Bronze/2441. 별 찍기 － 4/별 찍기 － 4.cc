#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) {
        string s1(n - i, ' ');
        string s(i, '*');
        cout << s1 + s << '\n';
    }

}