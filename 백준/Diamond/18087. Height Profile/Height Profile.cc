#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

struct Data {

    ll l, r;
    ll idx;

    void pf() {
        cout << l << ' ' << r << ' ' << idx << '\n';
    }
};

bool cmp1(Data& d1, Data& d2) {
    return min(d1.l, d1.r) < min(d2.l, d2.r);
}
bool cmp2(Data& d1, Data& d2) {
    return  d1.l < d2.l;
}
bool cmp3(Data& d1, Data& d2) {
    return d1.r < d2.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    cout << fixed << setprecision(9);

    vector<ll>A(n + 1);
    for (auto& i : A) cin >> i;

    ll minG = A[1] - A[0], maxG = A[1] - A[0];
    for (int i = 2; i <= n; i++) {
        minG = min(minG, A[i] - A[i - 1]);
        maxG = max(maxG, A[i] - A[i - 1]);
    }

    while (k--) {

        // query
        string s;
        //cin >> s;

        ld x;
        cin >> x;
        ll g = x * 10;

        //cout << "CURR: " << g << '\n';
        if (g>maxG) {
            cout << "impossible\n";
            continue;
        }
        g = max(g, minG);

        // y = gx + c

        vector<Data> B, B2;
        vector<ll> L(n), R(n);
        for (ll i = 0; i < n; i++) {

            // i, A[i] -> i+1, A[i+1]

            L[i] = A[i] - i * g;
            R[i] = A[i + 1] - (i + 1) * g;

            B.push_back({ L[i], R[i], i });
            B2.push_back({ L[i], R[i], i });
        }


        sort(B.begin(), B.end(), cmp1);
        sort(B2.begin(), B2.end(), cmp2);

        ld ans = 0;

        priority_queue<ll> pq;
        ll ix = 0;
        for (int i = 0; i < n; i++) {
            while (ix < n && min(B[ix].l, B[ix].r) <= B2[i].l) {
                pq.push(B[ix].idx);
                ix++;
            }

            while (!pq.empty()) {
                ll tx = pq.top();
                if (max(L[tx], R[tx]) < B2[i].l) pq.pop();
                else break;
            }

            if (A[n] - A[i] >= g * (n - i)) ans = max(ans, (ld)(n - i));

            if (!pq.empty()) {
                ll tx = pq.top();


               // cout <<"Found: " <<B2[i].idx <<' ' <<tx <<' ';
                // tx, A[tx] -> tx+1, A[tx+1]
                // y = gx + B2[i].l 교점 구하기

                ld pos1 = -1;
                if (g * (tx + 1) + B2[i].l == A[tx + 1]) pos1 = tx + 1;
                else {

                    ld c1 = 1.0*(A[tx + 1] - A[tx]) - g;
                    ld c2 = 1.0 * B2[i].l + 1.0 * g * tx - A[tx];

                    if (c1 == 0)pos1 = tx + 1;
                    else {
                        pos1 = c2 / c1 + tx;
                    }
                }
               // cout <<pos1 <<'\n';
                ans = max(ans, pos1 - B2[i].idx);
            }
        }
        while (!pq.empty())pq.pop();

        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        sort(B2.begin(), B2.end(), cmp3);

        ix = 0;
        for (ll i = 0; i < n; i++) {
            while (ix < n && min(B[ix].l, B[ix].r) <= B2[i].r) {
                pq2.push(B[ix].idx);
                ix++;
            }

            while (!pq2.empty()) {
                ll tx = pq2.top();
                if (max(L[tx], R[tx]) < B2[i].r) pq2.pop();
                else break;
            }

            if (A[i + 1] - A[0] >= g * (i + 1)) ans = max(ans, (ld)(i + 1));

            if (!pq2.empty()) {
                ll tx = pq2.top();


               // cout <<"found: " <<B2[i].idx+1 <<' ' <<tx <<' ';
                // tx, A[tx] -> tx+1, A[tx+1]
                // y = gx + B2[i].l 교점 구하기

                ld pos1 = -1;
                if (g * tx+B2[i].r == A[tx]) pos1 = tx;
                else {

                    ld c1 = 1.0*(A[tx + 1] - A[tx]) - g;
                    ld c2 = 1.0 * B2[i].r + 1.0 * g * tx - A[tx];

                    if (c1 == 0)pos1 = tx;
                    else {
                        pos1 = c2 / c1 + tx;
                    }
                }

                //cout <<pos1 <<'\n';
                ans = max(ans, B2[i].idx + 1 - pos1);
            }


        }
        while (!pq2.empty())pq2.pop();


        cout << ans << '\n';
    }
}
