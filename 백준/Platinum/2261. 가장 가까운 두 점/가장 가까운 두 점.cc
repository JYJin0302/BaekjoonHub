#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int n;
vector<pair<int, int>> A;
const int INF = INT_MAX;


int dist2(pair<int, int>& p1, pair<int, int>& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int solve(int l, int r) {
    int res = INF;
    if (r - l <= 3) {
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                res = min(res, dist2(A[i], A[j]));
            }
        }
        return res;
    }

    int md = (l + r) >> 1;

    int valL = solve(l, md);
    int valR = solve(md + 1, r);

    int d = min(valL, valR);

    vector<pair<int, int>> B;
    for (int i = l; i <= r; i++) {
        if ((A[i].x - A[md].x)* (A[i].x - A[md].x) <= d) B.push_back(mp(A[i].y, A[i].x));
    }
    sort(all(B));

    int sz = B.size();
    for (int i = 0; i < sz; i++) {
        for (int j = 1; j <= 11 && i - j >= 0; j++) {
            res = min(res, dist2(B[i], B[i - j]));
        }
    }
    res = min(res, d);
    return res;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    A = vector<pair<int, int>>(n);
    for (auto& i : A) cin >> i.x >> i.y;
    sort(all(A));

    cout << solve(0, n - 1);
}