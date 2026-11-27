#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair

map<int, int> ck;

int ans[1001010];
int L[1001010], R[1001010];
bool ok = 1;

bool isP[10010010];
vector<int> p;

void getAns(int l, int r, int pv = 0) {
    if (l > r) return;
    int tl = l, tr = r;
    while (tl <= tr) {
        if (L[tl] <= l && r <= R[tl]) {
            ans[tl] = pv;
            getAns(l, tl - 1, tl);
            getAns(tl + 1, r, tl);
            return;
        }
        tl++;
        if (L[tr] <= l && r <= R[tr]) {
            ans[tr] = pv;
            getAns(l, tr - 1, tr);
            getAns(tr + 1, r, tr);
            return;
        }
        tr--;
    }

    ok = 0;
}

void solve() {

    int n;
    cin >> n;
    vector<int>A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    for (int i = 1; i <= n; i++) {
        L[i] = 1;
        R[i] = n;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> pL;
        int ta = A[i];
        if (!isP[ta]) {
            pL.push_back(ta);
            ta = 1;
        }

        for (int f : p) {
            if (f * f > ta) break;
            if (ta % f == 0) {
                pL.push_back(f);
                while (ta % f == 0) ta /= f;
            }
        }
        if (ta != 1) pL.push_back(ta);

        for (auto f : pL) {
            int tv = ck[f];
            if (tv != 0) {
                R[tv] = min(R[tv], i - 1);
                L[i] = max(L[i], tv + 1);
            }
            ck[f] = i;
        }
    }

    getAns(1, n);

    if (!ok) {
        cout << "impossible";
        return;
    }

    for (int i = 1; i <= n; i++)cout << ans[i] << ' ';
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    isP[1] = 1;
    for (int i = 2; i <= 10000000; i++) {
        if (!isP[i]) {
            p.push_back(i);
            for (int j = i * 2; j <= 10000000; j += i) isP[j] = 1;
        }
    }

    solve();

    return 0;
}
