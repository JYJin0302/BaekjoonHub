#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;
    A.push_back(0);

    sort(A.begin(), A.end());
    n++;

    int l = A[1] - A[0];
    int r = A[2] - A[0];
    for (int i = 2; i < n; i++) {
        l = max(l, A[i] - A[i - 1]);
        
        if (i + 1 < n) {
            r = min(r, A[i + 1] - A[i - 1]);
        }
    }
    //cout << l << ' ' << r << '\n';
    if (l >= r) cout << 0;
    else cout << l;

}
