#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

int n, k;

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
    ll val = a.x * b.y - a.y * b.x;

    if (val == 0) {
        return a.x * a.x + a.y * a.y < b.x* b.x + b.y * b.y;
    }
    return val > 0;
}

ll ccw(pair<ll, ll>& a, pair<ll, ll>& b, pair<ll, ll>& c) {
    ll val = a.x * b.y + b.x * c.y + c.x * a.y;
    val -= a.y * b.x + b.y * c.x + c.y * a.x;
    return val;
}

void solve() {
    cin >> n >> k;

    vector<pair<ll, ll>> A(n), org;
    for (auto& i : A) cin >> i.x >> i.y;
    sort(all(A));

    int ans = 0;
    org = A;
    org.erase(org.begin());

    for (int i = 1; i < n - 1; i++) {
        org[i].x -= org[0].x;
        org[i].y -= org[0].y;
    }
    org[0] = mp(0, 0);
    sort(all(org), cmp);

    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (st.size() >= 2) {
            int b = st.top(); st.pop();
            int a = st.top();

            if (ccw(org[a], org[b], org[i % (n - 1)]) <= 0) {}
            else {
                st.push(b);
                break;
            }
        }
        st.push(i % (n - 1));
    }
    if (st.size() == k + 1) ans++;
    while (!st.empty()) st.pop();


    for (int i = 1; i < n; i++) {
        A[i].x -= A[0].x;
        A[i].y -= A[0].y;
    }
    A[0] = mp(0, 0);

    sort(all(A), cmp);

    /*cout << "SORTEd\n";
    for (auto f : A) cout << f.first << ' ' << f.second << '\n';*/


    for (int i = 0; i <= n; i++) {
        while (st.size() >= 2) {
            int b = st.top(); st.pop();
            int a = st.top();

            if (ccw(A[a], A[b], A[i % n]) <= 0) {}
            else {
                st.push(b);
                break;
            }
        }
        st.push(i % n);
    }

    vector<int> ch;
    while (!st.empty()) {
        ch.push_back(st.top());
        st.pop();
    }

    reverse(all(ch));
    ch.pop_back();

    int sz = ch.size();
    if (sz == k) ans += n - sz;

    for (int i = 1; i < sz; i++) {
        // ch[i]를 없애면 어떻게되나?

        int pv1 = (i - 1 + sz) % sz; pv1 = ch[pv1];
        int nx1 = (i + 1) % sz;
        int nx2 = (ch[nx1] + 1) % n;

        // cout << "Go: " << ch[i] << ' ' << pv1 << " - " << nx2 << '\n';

        for (int f = pv1; f != nx2 || st.size() <= 1; f = (f + 1) % n) {
            //cout << f << ' ';
            if (f == ch[i]) continue;
            while (st.size() >= 2) {
                int b = st.top(); st.pop();
                int a = st.top();

                if (ccw(A[a], A[b], A[f]) <= 0) {}
                else {
                    st.push(b);
                    break;
                }
            }
            st.push(f);
        }
        //cout << '\n';
        int dif = st.size() - 3;
        //cout << dif << '\n';

        if (sz + dif == k) ans++;
        while (!st.empty()) st.pop();
    }

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}