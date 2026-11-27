#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b) {

    vector<vector<int>> res(a.size(), vector<int>(a[0].size()));
    for (int k = 0; k < a.size(); k++) {
        for (int i = 0; i < a.size(); i++) {
            int temp = 0;
            for (int j = 0; j < a.size(); j++) {
                temp += a[k][j] * b[j][i];
                temp %= 1000;
            }
            res[k][i] = temp;
        }
    }

    return res;
}

vector<vector<vector<int>>> A;

int main() {

    int n;
    ll b;
    cin >> n >> b;

    b--;
    int cnt = 1;
    ll size = 1;
    while (size <= b) {
        size *= 2;
        cnt++;
    }
    cnt--;    

    vector<vector<int>> base(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> base[i][j];
        }
    }

    if (b == 0) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << base[i][j] % 1000 << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    vector<vector<vector<int>>> A(cnt);
    vector<int> bb(cnt);
    for (int i = 0; i < cnt; i++) {
        bb[i] = b % 2;
        b /= 2;
    }

    A[0] = base;
    
    for (int i = 1; i < cnt; i++) {
        A[i] = mult(A[i - 1], A[i - 1]);
    }

    vector<vector<int>> ans = A[0];
    for (int i = 0; i < cnt; i++) {
        if (bb[i] == 1) ans = mult(ans, A[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

}