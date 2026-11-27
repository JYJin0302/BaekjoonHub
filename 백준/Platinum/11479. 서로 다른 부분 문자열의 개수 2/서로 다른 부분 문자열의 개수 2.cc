#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> get_sa(const vector<int>& A, bool order = false) {
    vector<int> a = A;
    a.push_back(-1);
    int N = a.size();
    vector<int> sa(N), c(N);
    vector<pi> tmp(N), new_tmp(N);
    for (int i = 0; i < N; i++) {
        tmp[i] = { a[i],i };
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < N; i++) {
        sa[i] = tmp[i].second;
    }
    c[sa[0]] = 0;
    for (int i = 1; i < N; i++) {
        if (tmp[i].first == tmp[i - 1].first) {
            c[sa[i]] =
                c[sa[i - 1]];
        }
        else { c[sa[i]] = c[sa[i - 1]] + 1; }
    }
    for (ll k = 1; k < N; k <<= 1) {
        vector<pair<pair<int, int>, int>> tmp(N), new_tmp(N);
        for (int i = 0; i < N; i++) {
            tmp[i].first = { c[(sa[i] - k + N) % N],c[sa[i]]
            };
            tmp[i].second = (sa[i] - k + N) % N;
        }
        vector<int> cnt(N), p(N);
        for (int i = 0; i < N; i++) {
            cnt[tmp[i].first.first]++;
        }
        for (int i = 1; i < N; i++) {
            p[i] = p[i - 1] + cnt[i - 1];
            if (p[i] == N) { break; }
        }
        for (int i = 0; i < N; i++) {
            new_tmp[p[tmp[i].first.first]] = tmp[i];
            p[tmp[i].first.first]++;
        }
        swap(tmp, new_tmp);
        for (int i = 0; i < N; i++) { sa[i] = tmp[i].second; }
        c[sa[0]] = 0;
        for (int i = 1; i < N; i++) {
            if (tmp[i].first == tmp[i - 1].first) {
                c[sa[i]] = c[sa[i - 1]];
            }
            else {
                c[sa[i]] = c[sa[i - 1]] + 1;
            }
        }
        if (c[sa[N - 1]] == N - 1) { break; }
    }
    if (order) { return c; }
    else { return sa; }
}
vector<int> get_lcp(const vector<int>& A) {
    vector<int> sa = get_sa(A);
    vector<int> c = get_sa(A, 1);
    vector<int> a = A;
    a.push_back(-1);
    int N = a.size();
    vector<int> lcp(N);
    int d = 0;
    for (int j = 0; j < N - 1; j++) {
        int x = c[j]; int i = sa[x - 1];
        while (a[j + d] == a[i + d]) { ++d; }
        lcp[x] = d;
        d = max(d - 1, 0);
    }
    return lcp;
}

void solve() {
    string s;
    cin >> s;

    vector<int> tmp;
    for (int i = 0; i < s.size(); i++) tmp.push_back(s[i] - 'a');
    vector<int> t = get_lcp(tmp);

    ll n = s.size();
    ll ans = n * (n + 1) / 2;
    for (auto f : t) ans -= f;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}