#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct D {
    int a, b, c;
    bool operator<(D& o) {
        if (b == o.b) return a < o.a;
        return b < o.b;
    }
};

int root[50505];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

int lim = 50010;
int seg[101010];
void update(int ix, int val) {
    for (ix += lim; ix; ix >>= 1) {
        seg[ix] += val;
    }
}

int getS(int l, int r) {
    int res = 0;
    for (l += lim, r += lim; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

void solve() {

    int n;
    cin >> n;
    vector<D> A(n);
    for (auto& i : A) {
        cin >> i.a >> i.b >> i.c;
        i.a++, i.b++;
    }
    sort(all(A));

    for (int i = 1; i <= 50100; i++) root[i] = i;
    for (auto f : A) {
        int a = f.a, b = f.b;
        int ix = b, cnt = getS(a, b+1);
        while (cnt < f.c){
            int nx = find(ix);
            cnt++;
            root[nx] = nx - 1;
            ix = nx;
            update(nx, 1);
        }
    }

    cout << getS(0, lim + 1);


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
