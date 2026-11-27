#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, string>& a, pair<string,string>& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<string, string>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;

    sort(A.begin(), A.end(), cmp);

    for (auto i : A) cout << i.first << ' ' << i.second << '\n';
}