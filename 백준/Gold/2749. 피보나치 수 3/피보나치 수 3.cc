#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<vector<ll>> mult(vector<vector<ll>> a, vector<vector<ll>> b) {

    vector<vector<ll>> res(a.size(), vector<ll>(a[0].size()));
    for (int k = 0; k < a.size(); k++) {
        for (int i = 0; i < a.size(); i++) {
            ll temp = 0;
            for (int j = 0; j < a.size(); j++) {
                temp += a[k][j] * b[j][i];
                temp %= 1000000;
            }
            res[k][i] = temp;
        }
    }

    return res;
}

int main() {

    ll n;
    cin >> n;
    n--;
    if (n == 0){
        cout << 1;
        return 0;
    }
    
    int cnt = 1;
    ll size = 1;
    while (size <= n) {
        size *= 2;
        cnt++;
    }
    cnt--;


    vector<vector<vector<ll>>> A(cnt);
    A[0] = { {1, 1}, {1, 0} };
    
    for (int i = 1; i < cnt; i++) {
        A[i] = mult(A[i - 1], A[i - 1]);
    }

    vector<vector<ll>> ans = A[0];
    vector<int> bb(cnt);
    for (int i = 0; i < cnt; i++) {
        bb[i] = n % 2;
        n /= 2;
    }
    for (int i = 0; i < cnt; i++) {
        if (bb[i] == 1) ans = mult(ans, A[i]);
    }

    cout << ans[0][1];
}