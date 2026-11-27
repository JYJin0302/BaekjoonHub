#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    int ix1, ix2;
    vector<bool> chk(n);
    for (ix1 = 0, ix2 = 0; ix1 < n && ix2 < n; ) {
        if (A[ix1] == B[ix2]) {
            chk[ix1] = 1;
            ix2++;
            while (ix2 < n && B[ix2] == B[ix2 - 1]) ix2++;
        }
        ix1++;
    }

    if (ix2 < n) {
        cout << -1;
        return 0;
    }

    ix1 = 0;
    while (ix1 < n && !chk[ix1]) ix1++;

    vector<pair<int, pair<int, int>>> ans;

    for (int i = ix1 - 1; i >= 0; i--) {
        if (A[i] == A[i + 1]) {}
        else if (A[i] > A[i + 1]) {
            ans.push_back(mp(1, mp(i, i + 1)));
        }
        else {
            ans.push_back(mp(0, mp(i, i + 1)));
        }
        A[i] = A[i + 1];
    }

    while (ix1 + 1 < n) {
        if (!chk[ix1 + 1]) {
            if (A[ix1] > A[ix1 + 1]) {
                ans.push_back(mp(0, mp(ix1, ix1 + 1)));
            }
            else if (A[ix1] < A[ix1 + 1]) {
                ans.push_back(mp(1, mp(ix1, ix1 + 1)));
            }
            A[ix1 + 1] = A[ix1];
        }
        else {}
        ix1++;
    }

    vector<pair<int, pair<int, int>>> pA, pB;

    int ix = 0;
    while (ix < n) {
        int s = ix;
        while (ix < n && A[ix] == A[s]) ix++;

        pA.push_back(mp(A[s], mp(s, ix - 1)));
    }
    ix = 0;
    while (ix < n) {
        int s = ix;
        while (ix < n && B[ix] == B[s]) ix++;

        pB.push_back(mp(B[s], mp(s, ix - 1)));
    }

    stack<pair<int, pair<int, int>>> st;

    bool cs = 0;
    for (int i = 1; i < pA.size(); i++) {
        int u, v;
        u = pA[i].second.first;
        v = pB[i].second.first;

        if (u >= v) {
            if (cs) {
                while (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            cs = 0;


            if (u == v) continue;

            bool op = pA[i - 1].first > pA[i].first;
            ans.push_back(mp(op, mp(v, u)));
        }
        else {
            if (!cs) {
                while (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            cs = 1;

            bool op = pA[i - 1].first < pA[i].first;
            st.push(mp(op, mp(u - 1, v - 1)));
        }
    }
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    cout << ans.size() << '\n';
    for (auto& it : ans) {
        cout << (it.first ? 'm' : 'M') << " " << it.second.first+1 << " " << it.second.second+1 << "\n";
    }

}