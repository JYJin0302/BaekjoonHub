#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
vector<int> A;

void oper(int l, int r) {
    while (l < r) {
        swap(A[l], A[r]);
        l++, r--;
    }
}

bool check() {

    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return 0;
    }
    return 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    A = vector<int>(n);
    for (auto& i : A) cin >> i;

    vector<int> idx = { 0 };
    for (int i = 1; i < n - 1; i++) {
        if (abs(A[i] - A[i - 1]) != 1 || abs(A[i] - A[i + 1]) != 1) idx.push_back(i);
    }
    idx.push_back(n - 1);

    int m = idx.size();

    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            // first segment set
            oper(idx[i], idx[j]);


            vector<int> tidx;
            if (A[0] != 1) tidx.push_back(0);
            for (int i = 1; i < n - 1; i++) {
                if (abs(A[i] - A[i - 1]) != 1 || abs(A[i] - A[i + 1]) != 1) tidx.push_back(i);
            }
            if (A[n-1] != n) tidx.push_back(n - 1);

            int tm = tidx.size();
            if (tm > 8) {
                oper(idx[i], idx[j]);
                continue;
            }

            for (int x = 0; x < tm; x++) {
                for (int y = x; y < tm; y++) {
                    // second segment set
                    oper(tidx[x], tidx[y]);

                    vector<int> ttidx;
                    if (A[0] != 1) ttidx.push_back(0);
                    for (int i = 1; i < n - 1; i++) {
                        if (abs(A[i] - A[i - 1]) != 1 || abs(A[i] - A[i + 1]) != 1) ttidx.push_back(i);
                    }
                    if (A[n - 1] != n) ttidx.push_back(n - 1);

                    int tmm = ttidx.size();
                    if (tmm > 4) {
                        oper(tidx[x], tidx[y]);
                        continue;
                    }


                    for (int a = 0; a < tmm; a++) {
                        for (int b = 0; b < tmm; b++) {

                            oper(ttidx[a], ttidx[b]);

                            //check
                            if (check()) {
                                cout << idx[i] + 1 << ' ' << idx[j] + 1 << '\n';
                                cout << tidx[x] + 1 << ' ' << tidx[y] + 1 << '\n';
                                cout << ttidx[a] + 1 << ' ' << ttidx[b] + 1;
                                return 0;
                            }
                            oper(ttidx[a], ttidx[b]);
                        }
                    }

                    oper(tidx[x], tidx[y]);
                }
            }

            oper(idx[i], idx[j]);
        }
    }
}