#include <bits/stdc++.h>
using ll = long long;
using namespace std;


struct Point {
    int x, y;
};

struct Line {
    Point s, e;
};

int ccw(Point a, Point b, Point c) {
    int val = a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
    if (val != 0) val /= abs(val);
    return val;
}

bool isConn(Line& a, Line& b) {
    int c1 = ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e);
    int c2 = ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e);

    return (c1 == -1 && c2 == -1);
}

const int MAX_N = 6010;

vector<int> adj[MAX_N];
vector<int> rev[MAX_N];
bool visited[MAX_N];
int rep[MAX_N];
int topo[MAX_N];
stack<int> st;

void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (!visited[i]) {
        visited[i] = 1;
        dfs(i, v);
    }
    st.push(v);
}

void dfs2(int v, int val) {
    for (auto i : rev[v]) if (rep[i] == 0) {
        rep[i] = val;
        dfs2(i, val);
    }
}


void solve() {

    int n;
    cin >> n;

    vector<Line> A(n*3+1);
    for(int i = 1; i <= n*3; i++) {
        Point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;

        A[i] = { a, b };
    }

    for (int i = 1; i <= n * 3; i++) {
        for (int j = i + 1; j <= n * 3; j++) {
            if (isConn(A[i], A[j])) {

                adj[i].push_back(j + n * 3);
                adj[j].push_back(i + n * 3);

                rev[j + n * 3].push_back(i);
                rev[i + n * 3].push_back(j);

            }
        }
    }

    for (int i = 1; i <= 3*n; i+=3) {

        adj[i + n * 3].push_back(i + 1);
        adj[i + n * 3].push_back(i + 2);
        adj[i + 1 + n * 3].push_back(i + 2);
        adj[i + 1 + n * 3].push_back(i);
        adj[i + 2 + n * 3].push_back(i);
        adj[i + 2 + n * 3].push_back(i + 1);

        rev[i].push_back(i + 1 + n * 3);
        rev[i].push_back(i + 2 + n * 3);
        rev[i + 1].push_back(i + n * 3);
        rev[i + 1].push_back(i + 2 + n * 3);
        rev[i + 2].push_back(i + n * 3);
        rev[i + 2].push_back(i + 1 + n * 3);

    }


    for (int i = 1; i <= n*6; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }
    int cnt = 0;
    while (!st.empty()) {

        int a = st.top();
        st.pop();

        if (rep[a] != 0) continue;

        rep[a] = ++cnt;
        dfs2(a, rep[a]);
    }

    bool valid = 1;
    for (int i = 1; i <= n * 3; i++) {
        if (rep[i] == rep[i + n * 3]) valid = 0;
    }

    if (!valid) {
        cout << -1;
        return;
    }

    vector<int> ans;
    for (int i = 1; i <= 3 * n; i++) {
        if (rep[i] < rep[i + n * 3]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}