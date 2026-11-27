#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int root[303030];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> cap(n), cur(n);
    for (auto& i : cap) cin >> i;

    vector<int> nxt(n, n + 1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && cap[st.top()] < cap[i]) {
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n + 10; i++) root[i] = i;


    ll a, b;
    while (q--) {
        char c;
        cin >> c;

        if (c == '+') {
            cin >> a >> b;

            a--;
            a = find(a);
            while (b && a < n) {
                ll mn = min(b, cap[a] - cur[a]);
                cur[a] += mn;
                b -= mn;

                if (cur[a] == cap[a]) {
                    root[a] = nxt[a];
                    a = find(a);
                }
            }

        }
        else {
            cin >> a;
            cout << cur[a - 1] << '\n';
        }

    }
}