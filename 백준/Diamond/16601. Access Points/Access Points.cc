#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(10);

    int n;
    cin >> n;

    vector<ll> A(n), B(n);
    vector<long double> ansX(n), ansY(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }

    stack<pair<ll, ll>> st;
    st.push({ A[0], 1 });
    for (int i = 1; i < n; i++) {
        st.push({ A[i], 1 });

        while (st.size() >= 2) {

            ll x1, y1;
            ll x2, y2;
            tie(x1, y1) = st.top();
            st.pop();
            tie(x2, y2) = st.top();

            if (x2 * y1 <= x1 * y2) {
                // ok
                st.push({ x1, y1 });
                break;
            }
            else {
                st.pop();
                st.push({ x1 + x2, y1 + y2 });
            }
        }
    }

    int ix = n - 1;
    while (ix >= 0 && !st.empty()) {

        ll x, y;
        tie(x, y) = st.top();
        st.pop();

        for (int i = 0; i < y; i++) {
            ansX[ix] = 1.0 * x / y;
            ix--;
        }

    }

    swap(ansX, ansY);
    swap(A, B);


    st.push({ A[0], 1 });
    for (int i = 1; i < n; i++) {
        st.push({ A[i], 1 });

        while (st.size() >= 2) {

            ll x1, y1;
            ll x2, y2;
            tie(x1, y1) = st.top();
            st.pop();
            tie(x2, y2) = st.top();

            if (x2 * y1 <= x1 * y2) {
                // ok
                st.push({ x1, y1 });
                break;
            }
            else {
                st.pop();
                st.push({ x1 + x2, y1 + y2 });
            }
        }
    }

    ix = n - 1;
    while (ix >= 0 && !st.empty()) {

        ll x, y;
        tie(x, y) = st.top();
        st.pop();

        for (int i = 0; i < y; i++) {
            ansX[ix] = 1.0 * x / y;
            ix--;
        }

    }

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (ansY[i] - B[i]) * (ansY[i] - B[i]) + (ansX[i] - A[i]) * (ansX[i] - A[i]);
    }
    cout << ans;
}
