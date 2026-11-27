#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// -N ~ 0 ~ +N
//  0 ~ N ~ 2N
int n, x;
vector<int> fw;

void insert(int ix, int num) {
    while (ix <= n * 2) {
        fw[ix] += num;
        ix += ix & -ix;
    }
}

int ssum(int ix) {
    int res = 0;
    while (ix) {
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;

    fw = vector<int>(n * 2+1);
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a >= x) A[i] = 1;
        else A[i] = -1;

        A[i] += A[i - 1];
    }

    ll ans = 0;
    insert(n, 1);
    for (int i = 1; i <= n; i++) {
        ans += ssum(A[i] + n);
        insert(A[i] + n, 1);
    }
    cout << ans;
}