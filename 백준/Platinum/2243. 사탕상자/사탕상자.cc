#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

void update(int l, int r, int n, int u, int v) {

    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] += v;
        return;
    }

    int mid = (l + r) / 2;
    update(l, mid, n * 2, u, v);
    update(mid + 1, r, n * 2 + 1, u, v);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int subsum(int l, int r, int n, int sl, int sr) {

    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int mid = (l + r) / 2;
    return subsum(l, mid, n * 2, sl, sr) + subsum(mid + 1, r, n * 2 + 1, sl, sr);

}

int main() {
ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;

    int size = 1;
    while (size < 1000000) size *= 2;

    seg = vector<int>(size * 2);

    for (int i = 0; i < n; i++) {

        int t;
        cin >> t;

        if (t == 2) {
            int a, b;
            cin >> a >> b;

            update(size, size * 2 - 1, 1, size + a, b);
        }
        else {
            int a;
            cin >> a;

            int f = -1;
            int l = 1, r = 1000000;
            while (l <= r) {

                int mid = (l + r) / 2;

                int ssum = subsum(size, size * 2 - 1, 1, size, size + mid);
                
                if (ssum >= a) {
                    f = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            cout << f << '\n';
            update(size, size * 2 - 1, 1, size + f, -1);
        }
    }
}