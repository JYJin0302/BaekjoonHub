#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A(6);
    for (auto& i : A) cin >> i;

    cout << 1 - A[0] << ' ' << 1 - A[1] << ' ' << 2 - A[2] \
        << ' ' << 2 - A[3] << ' ' << 2 - A[4] << ' ' << 8 - A[5];

}