#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
};

template<class P> bool onSegment(P a, P b, P c) {
    if ((c.x - a.x) * (b.y - c.y) == (b.x - c.x) * (c.y - a.y)) {}
    else return 0;
    if (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x)) {}
    else return 0;
    if (c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y)) {}
    else return 0;
    return 1;
}
template <class P> bool conn(P a, P b, P c, P d){
    if (onSegment(c, d, a)) return 1;
    if (onSegment(c, d, b)) return 1;
    if (onSegment(a, b, c)) return 1;
    if (onSegment(a, b, d)) return 1;

    if (a.x == b.x && c.x == d.x) return 0;
    if (a.y == b.y && c.y == d.y) return 0;
    int nx = 0, ny = 0;
    if (a.x == b.x) nx = a.x, ny = c.y;
    else nx = c.x, ny = a.y;
    P tmp(nx, ny);
    return onSegment(a, b, tmp) && onSegment(c, d, tmp);
}

vector<int> adj[6030];
int dist[6030];

void solve() {
    memset(dist, -1, sizeof(dist));
    int n;
    cin >> n >> n >> n;

    vector<pair<Point<int>, Point<int>>> A(n);
    for (int i = 0; i < n; i++) {
        int b;
        int x1, y1, x2, y2;
        cin >> b>> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1), p2(x2, y2);
        A[b-1] = mp(p1, p2);
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point s(x1, y1), e(x2, y2);

    int ix = 0;


    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (onSegment(A[i].first, A[i].second, s)) {
            q.push(i);
            dist[i] = 0;
        }

    }

    while (!q.empty()) {
        int a = q.front(); q.pop();
        if (a < n && onSegment(A[a].first, A[a].second, e)) {
            cout << dist[a] + 1 << '\n';
            return;
        }
        for (int j = 0; j < n; j++) {
            if (dist[j] != -1) continue;

            if (conn(A[a].first, A[a].second, A[j].first, A[j].second)) {
                dist[j] = dist[a] + 1;
                q.push(j);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}