#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int sz;
map<int, bool> isBorder;
map<int, int> bCnt;

vector<int> num, fw;

void update(int ix, int val) {
    while (ix <= sz) {
        fw[ix] += val;
        ix += ix & -ix;
    }
}

int ssum(int ix) {
    int res = 0;
    while (ix) {
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

int getIdx(int i) {
    return lower_bound(num.begin(), num.end(), i) - num.begin();
}

void solve() {

    int n, m;
    cin >> n >> m;

    isBorder.clear();
    num.clear();
    bCnt.clear();

    vector<pair<int, int>> A(n);
    for (auto& i : A) {
        cin >> i.x >> i.y;
        num.push_back(i.y);
    }
    sort(A.begin(), A.end());

    vector<tuple<int, bool, int, int>> area;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        area.push_back({ a, 0, c, d });
        area.push_back({ b, 1, c, d });
        num.push_back(c);
        num.push_back(d);
        isBorder[c] = 1;
        isBorder[d] = 1;
    }

    if (m == 0) {
        cout << "0\n";
        return;
    }
    num.push_back(-1);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    sort(area.begin(), area.end());

    sz = num.size();
    fw = vector<int>(sz+1);


    int ans = 0;
    int areaIdx = 0, pIdx = 0;
    //while (pIdx < n && A[pIdx].x < get<0>(area[0])) pIdx++;

    while (pIdx < n && areaIdx < m * 2) {
        if (get<0>(area[areaIdx]) < A[pIdx].x) {
            // add/delete lines

            int l = get<2>(area[areaIdx]);
            int r = get<3>(area[areaIdx]);

            int lx = getIdx(l), rx = getIdx(r);
            int df = (get<1>(area[areaIdx]) ? -1 : 1);

            update(lx, df);
            update(rx + 1, -df);
            areaIdx++;  
        }
        else if (get<0>(area[areaIdx]) > A[pIdx].x){

            int val = A[pIdx].y;
            int ix = getIdx(val);


            ans += ssum(ix);
            pIdx++;
        }
        else {
            // get<0>(area[areaIdx]) == A[pIdx].x
            int tx = A[pIdx].x;

            while (areaIdx < m * 2 && get<0>(area[areaIdx]) == tx && !get<1>(area[areaIdx])) {

               
                int l = get<2>(area[areaIdx]);
                int r = get<3>(area[areaIdx]);

                int lx = getIdx(l), rx = getIdx(r);
                int df = 1;

                update(lx, df);
                update(rx + 1, -df);

                areaIdx++;
            }

            while (pIdx < n && A[pIdx].x == tx) {

                int val = A[pIdx].y;
                int ix = getIdx(val);

                ans += ssum(ix);
                pIdx++;
            }

            while (areaIdx < m * 2 && get<0>(area[areaIdx]) == tx) {

                int l = get<2>(area[areaIdx]);
                int r = get<3>(area[areaIdx]);

                int lx = getIdx(l), rx = getIdx(r);
                int df = -1;

                update(lx, df);
                update(rx + 1, -df);

                areaIdx++;
            }

        }
    }

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}