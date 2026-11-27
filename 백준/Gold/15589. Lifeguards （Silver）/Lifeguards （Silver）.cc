#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        A.push_back({ a, b });
    }
    vector<int> minus(n);

    sort(A.begin(), A.end());

    int diff = 1000000000;
    int l = 0, r = 0, ans;
    for (auto i : A) {
        tie(a, b) = i;
        diff = min(diff, b - a);
        
        if (b <= r || (a <= l && b >= r)) diff = 0;
        if (a <= l) {
            diff = min(diff, abs(r - b));
        }
        else if (a < r) {
            diff = min(diff, a - l);
            diff = min(diff, b - r);
        }
        if (diff == 0) break;
        if (a >= r) tie(l, r) = {a, b};
        else tie(l, r) = { r, b };
    }
    
    l = 0, r = 0, ans = 0;
    for (auto i : A) {
        tie(a, b) = i;
        if (a <= r) {
            r = max(r, b);
        }
        else {
            ans += r - l;
            r = b;
            l = a;
        }
    }
    ans += r - l;

    cout << ans - diff;
}