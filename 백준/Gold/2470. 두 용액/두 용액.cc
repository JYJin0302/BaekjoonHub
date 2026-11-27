#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>A(n);
    for (auto& i : A) cin >> i;

    sort(A.begin(), A.end());

    int ans = A[0] + A[n - 1];
    int l = 0, r = n - 1;
    int ansl = l, ansr = r;
    int temp;
    while (l < r) {
        temp = A[l] + A[r];
        if (abs(ans) > abs(temp)) {
             ans = temp;
            ansl = l, ansr = r;
         }
        if (temp == 0) break;
        if (temp > 0) {
            r--;
        }
        else {
            l++;
        }
    }

    cout << A[ansl] << ' ' << A[ansr];
}