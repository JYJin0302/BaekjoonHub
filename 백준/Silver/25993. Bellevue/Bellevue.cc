#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {
    ll x, y;
};

ll ccw(P a, P b, P c) {
    return a.x* b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout << fixed << setprecision(10);

    ll ans1 = 0, ans2 = 1;

    int n;
    cin >> n;

    ll mH = 0;
    vector<P> A(n);
    for (auto& i : A) {
        cin >> i.x >> i.y;
        mH = max(mH, i.y);
    }
    stack<P> st;

    for (int i = 0; i < n; i++) {

        P curr = A[i];
        while (st.size() >= 2) {
            P t1, t2;
            t2 = st.top();
            st.pop();
            t1 = st.top();

            if (ccw(t1, t2, curr) >= 0) {

            }
            else {
                st.push(t2);
                break;
            }
        }
        
        if (!st.empty()) {
            P tmp = st.top();

            ll v1 = curr.y - tmp.y;
            ll v2 = curr.x - tmp.x;

            if (ans2 * v1 > ans1 * v2) {
                ans1 = v1;
                ans2 = v2;
            }
        }
        st.push(curr);

        if (curr.y == mH) break;
    }

    while (!st.empty()) st.pop();
    reverse(A.begin(), A.end());

    for (int i = 0; i < n; i++) {

        P curr = A[i];
        curr.x *= -1;
        while (st.size() >= 2) {
            P t1, t2;
            t2 = st.top();
            st.pop();
            t1 = st.top();

            if (ccw(t1, t2, curr) >= 0) {

            }
            else {
                st.push(t2);
                break;
            }
        }

        if (!st.empty()) {
            P tmp = st.top();

            ll v1 = curr.y - tmp.y;
            ll v2 = curr.x - tmp.x;

            if (ans2 * v1 > ans1 * v2) {
                ans1 = v1;
                ans2 = v2;
            }
        }
        st.push(curr);

        if (curr.y == mH) break;
    }

   // cout << ans1 << ' ' << ans2 << '\n';
    long double tt = 1.0 * ans1 / ans2;
    long double pi = 3.14159265358979323846;

    cout << atan(tt)*180/pi;

}