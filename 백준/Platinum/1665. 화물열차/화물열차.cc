#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {    

    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;
    int m;
    cin >> m;
    vector<pair<int, int>> B(m);
    for (auto& i : B) cin >> i.first >> i.second;

    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int lenA = A[i].second - A[i].first + 1;
            int lenB = B[j].second - B[j].first + 1;
            int s1 = A[i].first + B[j].first - 2;
            res.push_back(mp(s1, 1));
            res.push_back(mp(s1 + (min(lenA, lenB)), -1));
            res.push_back(mp(s1 + max(lenA, lenB), -1));
            res.push_back(mp(s1 + lenA + lenB, 1));
            //cout << "Go :" << i << ' ' << j << '\n';
            //cout << s1 << ' ' << s1 + min(lenA, lenB) << ' ' << s1 + max(lenA, lenB) << ' ' << s1 + lenA + lenB << '\n';
        }
    }

    int ansV = -1, ansI = -1;
    int val = 0;
    int pv = 0, pos = 0;

    sort(all(res));

    int ix = 0;
    while (ix < res.size()) {
        int a = res[ix].first, b = 0;
        while (ix < res.size() && a == res[ix].first) {
            b += res[ix++].second;
        }

        val += pv * (a - pos);
        if (val > ansV) {
            ansV = val;
            ansI = a;
        }
        pv += b;
        pos = a;
    }
    cout << ansI << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}