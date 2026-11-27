#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> xpos, ypos;
vector<pair<pair<int, int>, int>> seg[50505];

int getIdx(int val, vector<int>& v) {
    return lower_bound(all(v), val) - v.begin();
}

void solve() {

    int n;
    cin >> n;

    vector<pair<pair<int, int>, pair<int, int>>> A(n), B;
    for (auto& i : A) {
        cin >> i.x.x >> i.x.y >> i.y.x >> i.y.y;
        xpos.push_back(i.x.x);
        xpos.push_back(i.y.x);
        ypos.push_back(i.x.y);
        ypos.push_back(i.y.y);
    }

    sort(all(xpos));
    xpos.erase(unique(all(xpos)), xpos.end());
    sort(all(ypos));
    ypos.erase(unique(all(ypos)), ypos.end());


    for (int i = 0; i < n; i++) {
        int pos = getIdx(A[i].x.x, xpos);
        seg[pos].push_back(mp(mp(A[i].x.y, A[i].y.y), i));

        pos = getIdx(A[i].y.x, xpos);
        seg[pos].push_back(mp(mp(A[i].x.y, A[i].y.y), i));
    }

    vector<bool> chk(n + 1);

    for (int i = 0; i < xpos.size(); i++) {
        sort(all(seg[i]));

        int l = -1, r = -1, cur = -1;

        for (auto& f : seg[i]) {
            auto [a, b] = f.first;
            if (r >= a) {
                r = max(r, b);
                chk[f.y] = 1;
                chk[cur] = 1;
            }
            else {
                tie(l, r) = f.x;
                cur = f.y;
            }
        }
    }

    for (int i = 0; i < ypos.size(); i++) seg[i].clear();

    for (int i = 0; i < n; i++) {
        int pos = getIdx(A[i].x.y, ypos);
        seg[pos].push_back(mp(mp(A[i].x.x, A[i].y.x), i));
        pos = getIdx(A[i].y.y, ypos);
        seg[pos].push_back(mp(mp(A[i].x.x, A[i].y.x), i));
    }

    for (int i = 0; i < ypos.size(); i++) {
        sort(all(seg[i]));
        int l = -1, r = -1, cur = -1;
        for (auto& f : seg[i]) {
            auto [a, b] = f.first;
            if (r >= a) {
                r = max(r, b);
                chk[f.y] = 1;
                chk[cur] = 1;
            }
            else {
                tie(l, r) = f.x;
                cur = f.y;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!chk[i]) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}