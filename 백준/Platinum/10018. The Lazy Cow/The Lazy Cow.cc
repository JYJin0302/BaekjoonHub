#include <bits/stdc++.h>
using namespace std;

int N, K;
struct P {
    int x, y, v;

    bool operator<(P& other) {
        if (y != other.y) return y < other.y;
        return x < other.x;
    }
};

vector<int> xpos, seg, lazy;
int getIdx(int v) {
    return lower_bound(xpos.begin(), xpos.end(), v) - xpos.begin();
}

void goLazy(int l, int r, int n) {
    if (lazy[n] != 0) {
        seg[n] += lazy[n];
        if (l != r) {
            lazy[n * 2] += lazy[n];
            lazy[n * 2 + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void update(int l, int r, int n, int ul, int ur, int v) {
    goLazy(l, r, n);
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
        lazy[n] = v;
        goLazy(l, r, n);
        return;
    }

    int m = (l + r) >> 1;
    update(l, m, n * 2, ul, ur, v);
    update(m + 1, r, n * 2 + 1, ul, ur, v);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    vector<P> A(N);
    for (int i = 0; i < N; i++) {
        int v, a, b;
        cin >> v >> a >> b;
        A[i] = { a-b, a+b, v };
        xpos.push_back(a-b);
        xpos.push_back(a - b - K);
        xpos.push_back(a - b + K);
    }

    sort(xpos.begin(), xpos.end());
    xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());

    int sz = 1;
    while (sz < xpos.size()) sz *= 2;
    seg = vector<int>(sz * 2);
    lazy = vector<int>(sz * 2);

    sort(A.begin(), A.end());

   // for (auto& i : A) cout << i.x << ' ' << i.y << ' ' << i.v << '\n';

    int ans = 0;
    queue<P> q;
    for (const P& curr : A) {
        
        while (!q.empty()) {
            P& tmp = q.front();
            if (tmp.y < curr.y - 2 * K) {
                int ixL = getIdx(tmp.x - K);
                int ixR = getIdx(tmp.x + K);
                update(0, sz - 1, 1, ixL, ixR, -tmp.v);
                q.pop();
            }
            else break;
        }

        int ixL = getIdx(curr.x - K);
        int ixR = getIdx(curr.x + K);

        update(0, sz - 1, 1, ixL, ixR, curr.v);
        
        ans = max(ans, seg[1]);
        q.push(curr);
    }
    cout << ans;

}