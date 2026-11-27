#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {
    int n; cin >> n;

    string s;
    cin >> s;

    for (auto& f : s) {
        if (f == 's' || f == 'k' || f == 'e' || f == 'p') {}
        else f = 'x';
    }

    string tar = "skeep";
    int ans = 0;
    stack<char> st;
    for (auto f : s) {
        if (f == 'x') {
            while (!st.empty()) st.pop();
            continue;
        }

        if (f == 'p') {
            st.push(f);
            while (st.size() >= 5) {
                string ts;
                for (int i = 0; i < 5; i++) {
                    ts += st.top(); st.pop();
                }
                reverse(all(ts));
                bool ok = 1;
                for (int i = 0; i < 5; i++) {
                    if (ts[i] == tar[i] || (i > 0 && ts[i] == '?')) {}
                    else ok = 0;
                }

                if (ok) {
                    ans++;
                    st.push('?');
                }
                else {
                    if (ts.back() == 'p') {
                        while (!st.empty()) st.pop();
                    }
                    else {
                        for (auto d : ts) st.push(d);
                    }
                    break;
                }
            }
        }
        else st.push(f);
    }
    cout << ans << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}