#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bitset<2020> A[2020];
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            A[i][j] = (s[j] == '1');
        }
    }

    bitset<2020> tmp;
    int q;
    cin >> q;
    while (q--) {

        int a, b;
        cin >> a >> b;

        a--, b--;
        tmp = A[a] & A[b];
        cout << tmp.count() << '\n';
    }
}