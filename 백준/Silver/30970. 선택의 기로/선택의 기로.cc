#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

bool cmp(pair<int, int>& a, pair<int, int>&b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

bool cmp2(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;

    sort(A.begin(), A.end(), cmp);
    cout << A[0].first << ' ' << A[0].second << ' ' << A[1].first << ' ' << A[1].second << '\n';
    sort(A.begin(), A.end(), cmp2);
    cout << A[0].first << ' ' << A[0].second << ' ' << A[1].first << ' ' << A[1].second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
