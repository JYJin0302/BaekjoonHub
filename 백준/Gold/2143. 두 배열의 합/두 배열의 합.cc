#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    cin >> m;
    vector<int> B(m);
    for (auto& i : B) cin >> i;

    vector<int> sA(n), sB(m);
    sA[0] = A[0];
    sB[0] = B[0];
    for (int i = 1; i < n; i++) {
        sA[i] = sA[i - 1] + A[i];
    }
    for (int i = 1; i < m; i++) {
        sB[i] = sB[i - 1] + B[i];
    }

    vector<int> allA;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            allA.push_back(sA[j] - sA[i]);
        }
    }
    for (int i : sA) allA.push_back(i);
    sort(allA.begin(), allA.end());

    ll ans = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            int test = sB[j] - sB[i];
            ans += upper_bound(allA.begin(), allA.end(), t - test) - lower_bound(allA.begin(), allA.end(), t - test);
        }
    }
    for (int i = 0; i < m; i++) {
        int test = sB[i];
        ans += upper_bound(allA.begin(), allA.end(), t - test) - lower_bound(allA.begin(), allA.end(), t - test);
    }
    cout << ans;
}