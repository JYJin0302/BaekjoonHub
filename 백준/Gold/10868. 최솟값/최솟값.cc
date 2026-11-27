#include <bits/stdc++.h>
using namespace std;
#define INF 1987654321

vector<int> seg;

int n, m, ans, a, b;

void init(int l, int r, int node) {
    if (l == r) return;
    int mid = (l + r) / 2;

    init(l, mid, node * 2);
    init(mid + 1, r, node * 2 + 1);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

void search(int l, int r, int node, int sl, int sr) {
    if (l > sr || r < sl) return;
    if (l >= sl && r <= sr) {
        ans = min(ans, seg[node]);
        return;
    }

    int mid = (l + r) / 2;
    search(l, mid, node*2, sl, sr);
    search(mid + 1, r, node * 2 + 1, sl, sr);
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int size = 1;
    while (size < n) size *= 2;

    seg = vector<int>(size * 2, INF);
    for (int i = 0; i < n; i++) {
        cin >> seg[size + i];
    }
    init(size, size * 2 - 1, 1);



    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ans = INF;
        search(size, size*2-1, 1,size + a - 1,size + b-1);
        cout << ans << '\n';
    }

}