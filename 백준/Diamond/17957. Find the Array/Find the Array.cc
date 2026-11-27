#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> Q[522];
int tdx = -1;

vector<int> comple(vector<int>& a, vector<int>& b) {
    // a - b

    vector<int> res;

    int ai = 0, bi = 0;
    while (ai < a.size() && bi < b.size()) {

        if (a[ai] == b[bi]) {
            ai++, bi++;
        }
        else {
            if (a[ai] < b[bi]) {
                res.push_back(a[ai]);
                ai++;
            }
            else {
                bi++;
            }
        }
    }
    while (ai < a.size()) res.push_back(a[ai++]);
    return res;
}

vector<int> common(vector<int>& a, vector<int>& b) {

    vector<int> res;

    int ai = 0, bi = 0;
    while (ai < a.size() && bi < b.size()) {

        if (a[ai] == b[bi]) {
            res.push_back(a[ai]);
            ai++, bi++;
        }
        else {
            if (a[ai] < b[bi]) {
                ai++;
            }
            else {
                bi++;
            }
        }
    }
    return res;
}

vector<int> getDistList(vector<int>& a) {
    vector<int> res;
    int n = a.size();

    vector<int> inp1;
    if (n > 1) {
        cout << "2 " << n << ' ';
        for (auto i : a) cout << i << ' ';
        cout << endl;

        int k = n * (n - 1) / 2;
        inp1 = vector<int>(k);
        for (auto& i : inp1) cin >> i;
        sort(inp1.begin(), inp1.end());
    }

    cout << "2 " << a.size() + 1 << ' ';
    for (auto i : a) cout << i << ' ';
    cout << tdx << endl;

    int k = n * (n + 1) / 2;
    vector<int> inp2(k);
    for (auto& i : inp2) cin >> i;
    sort(inp2.begin(), inp2.end());

    return comple(inp2, inp1);
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<int> ans(n + 10);
    int x;

    if (n <= 30) {
        for (int i = 1; i <= n; i++) {
            cout << "1 " << i << endl;
            cin >> x;
            ans[i] = x;
        }

        cout << "3 ";
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
        return 0;
    }

    cout << "2 " << n << ' ';
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << endl;

    int k = n * (n - 1) / 2;
    vector<int> inp(k);
    for (auto& i : inp) cin >> i;

    sort(inp.begin(), inp.end());

    int mDist = inp.back();
    Q[0] = inp;

    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) >> 1;

        if (m == 1) {
            l = m + 1;
            continue;
        }

        cout << "2 " << m << ' ';
        for (int i = 1; i <= m; i++) cout << i << ' ';
        cout << endl;

        k = m * (m - 1) / 2;
        inp = vector<int>(k);
        for (auto& i : inp) cin >> i;

        int md = *max_element(inp.begin(), inp.end());
        if (md == mDist) {
            tdx = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    // cout << "Binary end\n";

     // tdx : max or min
    vector<int> tmp(n - 1);
    cout << "2 " << n - 1 << ' ';
    for (int i = 1; i <= n; i++) {
        if (i != tdx) cout << i << ' ';
    }
    cout << endl;

    k = (n - 1) * (n - 2) / 2;
    inp = vector<int>(k);
    for (auto& i : inp) cin >> i;
    sort(inp.begin(), inp.end());

    vector<int> b1 = comple(Q[0], inp);
    //  b1.push_back(0);

   //   sort(b1.begin(), b1.end());
    Q[1] = b1;

    vector<int> rdx;
    for (int i = 1; i <= n; i++) if (i != tdx) rdx.push_back(i);

    vector<tuple<int, int, int>> curr, next;
    curr.push_back({ 0, n - 2, 1 });

    while (1) {

        vector<int> lst;
        for (auto i : curr) {
            int a, b, m;
            tie(a, b, m) = i;

            if (a == b) {
                ans[rdx[a]] = Q[m][0];
                continue;
            }
            int mid = (a + b) / 2;

            next.push_back({ a, mid, m * 2 });
            next.push_back({ mid + 1, b, m * 2 + 1 });

            for (int j = a; j <= mid; j++) lst.push_back(rdx[j]);
        }
        if (lst.empty()) break;

        inp = getDistList(lst);
        for (auto i : next) {
            int a, b, m;
            tie(a, b, m) = i;

            if (m & 1) {
                Q[m] = comple(Q[m / 2], Q[m - 1]);
            }
            else {
                Q[m] = common(Q[m / 2], inp);
            }
        }

        curr = next;

        /*cout << "after: \n";
        for (auto i : curr) {
            int a, b, m;
            tie(a, b, m) = i;
            cout << a << ' ' << b << ' ' << m << " | ";

            for (auto k : Q[m]) cout << k << ' ';
            cout << '\n';
        }*/
        next.clear();
    }

    //for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

    int v1, v2;

    cout << "1 " << tdx << endl;
    cin >> v1;

    cout << "1 " << (tdx % n) + 1 << endl;
    cin >> v2;

    if (v1 > v2) {
        for (int i = 1; i <= n; i++) ans[i] = v1 - ans[i];
    }
    else {
        for (int i = 1; i <= n; i++) ans[i] += v1;
    }

    cout << "3 ";
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
}
