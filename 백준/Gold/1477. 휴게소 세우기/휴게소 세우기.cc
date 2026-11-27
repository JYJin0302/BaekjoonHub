#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> A(n);
    for (auto& i : A) cin >> i;
    A.push_back(0);
    A.push_back(l);
    sort(A.begin(), A.end());

    vector<int> B;
    for (int i = 1; i < n+2; i++) {
        B.push_back(A[i] - A[i - 1]);
    }

    int a = 1, b = l, ans = -1;
    while (a <= b) {

        int mid = (a + b) / 2;

        int nd = 0;
        for (auto i : B) {
            nd += (i-1) / mid;
        }

        if (nd <= m) {

            ans = mid;
            b = mid - 1;
        }
        else a = mid + 1;
    }
    cout << ans;


}