#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

string N[101010];

void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        cin >> N[i];

        int val = 0;
        int x;
        cin >> x;
        val += x * 10;
        vector<int> tmp(6);
        for (auto& f : tmp) cin >> f;
        sort(all(tmp));

        for (int j = 1; j < 5; j++) val += tmp[j];

        A.push_back(mp(val, -i));
    }

    sort(all(A));
    reverse(all(A));


    int ix = 0;
    while (ix < n) {
        if (ix >= 3) break;

        int tx = ix;
        while (ix < n && A[ix].x == A[tx].x) {
            cout << N[-A[ix].y] << ' ' << A[ix].x << '\n';
            ix++;
        }
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}