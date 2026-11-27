#include<bits/stdc++.h>
using namespace std;

int A[50][50], B[50][50];

void change(int x, int y) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[x - 1 + i][y - 1 + j] = 1 - A[x - 1 + i][y - 1 + j];
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            A[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            B[i][j] = s[j] - '0';
        }
    }

    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (A[i - 1][j - 1] != B[i - 1][j - 1]) change(i, j), cnt++;
        }
    }

    bool ok = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) ok = 0;
        }
    }

    if (ok) cout << cnt;
    else cout << -1;

}