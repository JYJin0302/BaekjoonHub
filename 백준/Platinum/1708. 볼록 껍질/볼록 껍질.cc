#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

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
    cin >> n;

    vector<pair<ll, ll>> A(n);
    for (auto& i : A) cin >> i.x >> i.y;
    sort(all(A));

    for (int i = 1; i < n; i++) {
        A[i].x -= A[0].x;
        A[i].y -= A[0].y;
    }
    A[0] = mp(0, 0);

    sort(all(A), cmp);

    /*cout << "SORTEd\n";
    for (auto f : A) cout << f.first << ' ' << f.second << '\n';*/

    stack<int> st;

    for (int i = 0; i <= n; i++) {
        while (st.size() >= 2) {
            int b = st.top(); st.pop();
            int a = st.top();

            if (ccw(A[a], A[b], A[i%n]) <= 0) {}
            else {
                st.push(b);
                break;
            }
        }
        st.push(i%n);
    }

    cout << st.size() - 1;
   /* while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }*/

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}