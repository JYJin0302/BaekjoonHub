#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.second != p2.second) return p1.second < p2.second;
    return p1.first > p2.first;
}
vector<int> num;
int getIdx(int x) {
    return lower_bound(all(num), x) - num.begin();
}

int sz;
int seg[2002020];

void update(int ix, int val) {
    for (ix += sz; ix; ix >>= 1) {
        seg[ix] = max(seg[ix], val);
    }
}
int getMax(int l, int r) {
    int res = 0;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (auto& i : A) {
        cin >> i.first >> i.first >> i.second;
        num.push_back(i.first);
        num.push_back(i.second);
    }
    sort(all(num));
    num.erase(unique(all(num)), num.end());
    for (auto& i : A) {
        i.first = getIdx(i.first);
        i.second = getIdx(i.second);
    }

    sort(all(A), cmp);
    A.erase(unique(all(A)), A.end());

    sz = num.size();

    int ans = 0;
    for (auto& [a, b] : A) {
        int v = getMax(a, b + 1);
        update(a, v + 1);
        ans = max(ans, v + 1);
    }
    cout << ans;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}