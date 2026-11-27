#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10);
    
    int n;
    cin >> n;

    int tot = 0;
    vector<int> A(n);
    for (auto& i : A) {
        cin >> i;
        tot += i;
    }

    

    int c;
    cin >> c;

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < c) continue;

        long double tans = 1;
        for (int j = 0; j < c; j++) {
            tans *= A[i] - j;
            tans /= tot - j;
        }
        ans += tans;
    }
    cout << ans;

}