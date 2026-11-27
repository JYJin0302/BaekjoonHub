#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T {
    int x, y, r;
};

const long double PI = 3.1415926535897;
vector<T> A;
int root[1001];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

long double getDist(int i, int j) {

    // collide
    int tdist = (A[i].x - A[j].x) * (A[i].x - A[j].x) + (A[i].y - A[j].y) * (A[i].y - A[j].y);

    if (tdist <= (A[i].r + A[j].r)*(A[i].r+A[j].r)) return 0;

    long double dist = sqrtl(tdist);
    if (A[i].r < A[j].r) swap(i, j);

    if (A[i].r == A[j].r) {
        return A[i].r * 2 * PI + dist * 2;
    }

    long double d1 = sqrtl(dist * dist - (A[i].r - A[j].r) * (A[i].r - A[j].r));
    long double tmp = asin(d1 / dist), tmp2 = acos(d1/dist);

    long double res = d1 * 2;
    res += A[i].r * (2*PI - 2*tmp);
    res += A[j].r * (PI - 2 * tmp2);
    return res;
}

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) root[i] = i;

    A = vector<T>(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].r;
    }

    priority_queue<tuple<long double, int, int>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pq.push({ -getDist(i, j), i, j });
        }
    }

    int conn = 0;
    long double ans = 0;
    while (conn < n - 1 && !pq.empty()) {
        long double x;
        int a, b;
        tie(x, a, b) = pq.top();
        pq.pop();

        if (find(a) == find(b)) continue;
        root[root[a]] = root[b];
        conn++;
        ans += -x;
    }
    cout << ans;

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15);

    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}