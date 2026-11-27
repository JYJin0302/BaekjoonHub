#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> A(m);
    for (int i = 0; i < m; i++) {
        if (s[i] == 'I')
        {
            A[i] = 1;
            if (i >= 2 && s[i-1] == 'O') A[i] += A[i - 2];
        }
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (A[i] >= n+1) ans++;
    }
    cout << ans;
}