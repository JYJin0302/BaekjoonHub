#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, s;
    cin >> n >> s;

    vector <pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;
    //reverse(all(A));

    set<int>::iterator iter;
    set<int> pos;
    map<int, int> val;

    pos.insert(A[0].first);
    pos.insert(A[0].second);

    val[A[0].first] = s - A[0].first;
    val[A[0].second] = A[0].second - s;
    
    for (int i = 1; i < n; i++) {
        auto& [l, r] = A[i];

        iter = pos.lower_bound(l);
        //cout << "GO : " << l << ' ' << r << '\n';

        int vala, valb;
        vala = valb = 1e9;
        while (iter != pos.end()) {
            if (*iter > r) break;

            int curr = *iter;
            //cout << "FOUnd: " << curr << '\n';
            vala = min(vala, val[curr] + abs(curr - l));
            valb = min(valb, val[curr] + abs(curr - r));
            pos.erase(iter++);
            val[curr] = 0;
        }

        if (vala != 1e9) {
            pos.insert(l);
            pos.insert(r);

            if (val[l] == 0) val[l] = vala;
            else val[l] = min(val[l], vala);
            if (val[r] == 0) val[r] = valb;
            else val[r] = min(val[r], valb);
        }

        //for (auto f : pos) cout << "{" << f << ',' << val[f] << "} ";
       // cout << '\n';
    }

    int ans = 1e9;
    for (auto f : pos) {
        ans = min(ans, abs(f) + val[f]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}