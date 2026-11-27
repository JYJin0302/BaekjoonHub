#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair

#define all(x) x.begin(), x.end()

bitset<155000> bs;

struct Data {
    int f, s, d;
    Data() : f(0), s(0), d(0) {}
    Data(int _f, int _s, int _d) : f(_f), s(_s), d(_d) {}

    bool operator<(Data& i) {
        if (s == i.s) return d > i.d;
        return s < i.s;
    }
};

void solve() {

    int n, q;
    cin >> n >> q;
    vector<Data> A(n);

    vector<int> ans(300030, -1);

    for (auto& i : A) {
        cin >> i.d >> i.f >> i.s;
    }
    sort(all(A));

    vector<int> sufMax(n), preMax(n);
    vector<ll> sufSum(n), preSum(n);
    for (int i = n - 1; i >= 0; i--) {
        sufMax[i] = A[i].f;
        if (i != n - 1) sufMax[i] = max(sufMax[i], sufMax[i + 1]);
        sufSum[i] = A[i].d;
        if (i != n - 1) sufSum[i] += sufSum[i + 1];
    }
    for (int i = 0; i < n; i++) {
        preMax[i] = A[i].s;
        if (i != 0) preMax[i] = max(preMax[i], preMax[i - 1]);
        preSum[i] = A[i].d;
        if (i != 0) preSum[i] += preSum[i - 1];
    }

    bs[0] = 1;

    ll len = sufSum[0];
    if (len <= 300000) {
        ans[len] = sufMax[0];
    }

    for (int i = 0; i < n; i++) {
        bs |= (bs << A[i].d);

        int md = 300010;
        if (preSum[i] > 600000) continue;
        int pS = preSum[i];
        for (int j = pS / 2; j >= 0; j--) {
            if (bs[j] == 1) {
                md = max(j, pS - j);
                break;
            }
        }

       // cout << "Go " << A[i].f << ' ' << A[i].s << ' '<< A[i].d << '\n';
        if (i+1 < n) md += sufSum[i + 1];
        if (md > 300000) continue;



        int t = preMax[i];
        if (i + 1 < n) t = max(t, sufMax[i + 1]);
        if (ans[md] == -1) ans[md] = t;
        else ans[md] = min(ans[md], t);
        //cout << md << ' ' << t << '\n';
    }

    for (int i = 1; i <= 300000; i++) {
        if (ans[i] == -1) ans[i] = ans[i - 1];
        else if (ans[i - 1] != -1) ans[i] = min(ans[i], ans[i - 1]);
    }


    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
