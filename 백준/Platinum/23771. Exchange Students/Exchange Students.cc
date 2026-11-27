#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, maxN;
vector<int> posA[300001], posB[300001];
vector<int> seg1, seg2;
ll ans = 0;
vector<pair<int, int>> res;

void update(int l, int r, int n, int u, int v, vector<int>& seg) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] = v;
        return;
    }
    int m = (l + r) >> 1;
    update(l, m, n * 2, u, v, seg);
    update(m + 1, r, n * 2 + 1, u, v, seg);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int getSum(int l, int r, int n, int sl, int sr, vector<int>& seg) {
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;
    return getSum(l, m, n * 2, sl, sr, seg) + getSum(m + 1, r, n * 2 + 1, sl, sr, seg);
}

int getIdx(int l, int r, int n, int cnt, vector<int>& seg) {

    if (l == r) {
        return l;
    }
    int m = (l + r) >> 1;

    int lft = seg2[n * 2];
    if (lft + cnt <= m-l+1) {
        return getIdx(l, m, n * 2, cnt, seg);
    }

    cnt -= (m - l + 1) - lft;
    return getIdx(m + 1, r, n * 2 + 1, cnt, seg);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<int> A(n), B(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    vector<int> num;
    for (auto i : A) num.push_back(i);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for (auto& i : A) {
        i = lower_bound(num.begin(), num.end(), i) - num.begin();
    }
    for (auto& i : B) {
        i = lower_bound(num.begin(), num.end(), i) - num.begin();
    }

    maxN = num.size();
    int sz = 1;
    while (sz < n) sz *= 2;

    seg1 = vector<int>(sz * 2);
    seg2 = vector<int>(sz * 2);

    for (int i = 0; i < n; i++) {
        posA[A[i]].push_back(i);
        posB[B[i]].push_back(i);
    }

    vector<bool> used(n);

    for (int i = 0; i < maxN; i++) {

        vector<tuple<int, int, int>> tmp;
        for (int j = 0; j < posA[i].size(); j++) {
            
            int curr = posA[i][j], to = posB[i][j];
            int val1 = curr - getSum(0, sz - 1, 1, 0, curr - 1, seg1);
            int val2 = getIdx(0, sz - 1, 1, val1+1, seg2);

          //  cout << "MOVE: " << val2 << " -> " << to << '\n';

            int tans = abs(val2 - to);
            if (val2 > to) tans -= getSum(0, sz - 1, 1, to, val2, seg2);
            else tans -= getSum(0, sz - 1, 1, val2, to, seg2);
            ans += tans;

            tmp.push_back({ val2, to, val1 });
        }

        vector<tuple<int, int, int>> ord;
        int ix = 0;
        stack<tuple<int, int, int>> st;
        while (ix < tmp.size()) {

            if (get<0>(tmp[ix]) > get<1>(tmp[ix])) {
                while (!st.empty()) {
                    ord.push_back(st.top());
                    st.pop();
                }
                ord.push_back(tmp[ix]);
            }
            else {
                while (!st.empty()) {
                    if (get<1>(st.top()) < get<0>(tmp[ix])) {
                        ord.push_back(st.top());
                        st.pop();
                    }
                    else break;
                }
                st.push(tmp[ix]);
            }
            ix++;
        }
        while (!st.empty()) {
            ord.push_back(st.top());
            st.pop();
        }

        for (auto j : ord) {
            int val1, val2, to;
            tie(val2, to, val1) = j;
            //cout << "CURR: " << val2 << ' ' << to << '\n';
            int tval = val1 + 1;
            for (int k = val2; k != to && res.size() < 200000; ) {
                int nk = k;
                if (k > to) {
                    nk--; tval--;
                }
                else {
                    nk++; tval++;
                }

                int ndx = getIdx(0, sz - 1, 1, tval, seg2);
                res.push_back({ ndx, k });
               // cout << "RES add: " << ndx << ' ' << k << '\n';
                k = ndx;
            }
        }

        for (int j = 0; j < posA[i].size(); j++) {
            update(0, sz - 1, 1, posA[i][j], 1, seg1);
            update(0, sz - 1, 1, posB[i][j], 1, seg2);
        }
    }

    cout << ans << '\n';

    for (int i = 0; i < min(200000, (int)res.size()); i++) {
        cout << res[i].first+1 << ' ' << res[i].second+1 << '\n';
    }
}