#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg1;

ll init1(int s, int f, int n) {

    if (s == f) return seg1[s];
    int mid = (s + f) / 2;

    int n1 = init1(s, mid, n * 2);
    int n2 = init1(mid + 1, f, n * 2 + 1);

    return seg1[n] = max(n1, n2);
}
vector<ll> seg2;

ll init2(int s, int f, int n) {

    if (s == f) return seg2[s];
    int mid = (s + f) / 2;

    int n1 = init2(s, mid, n * 2);
    int n2 = init2(mid + 1, f, n * 2 + 1);

    if (n1 == 0) return seg2[n] = n2;
    else if (n2 == 0) return seg2[n] = n1;
    else return seg2[n] = min(n1, n2);
}

ll submax(int s, int f, int n, int left, int right) {
    if (left > f || right < s) return 0;
    if (s >= left && f <= right) return seg1[n];

    int mid = (s + f) / 2;

    return max(submax(s, mid, n * 2, left, right), submax(mid + 1, f, n * 2 + 1, left, right));

}
ll submin(int s, int f, int n, int left, int right) {
    if (left > f || right < s) return 0;
    if (s >= left && f <= right) return seg2[n];

    int mid = (s + f) / 2;

    int n1 = submin(s, mid, n * 2, left, right);
    int n2 = submin(mid + 1, f, n * 2 + 1, left, right);
    if (n1 == 0) return n2;
    else if (n2 == 0) return n1;
    else return min(n1, n2);


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, a, b, c;
    cin >> n >> m;
    ll arrsize = 1;
    while (arrsize < n) arrsize *= 2;

    seg1 = vector<ll>(2 * arrsize);
    seg2 = vector<ll>(2 * arrsize);

    for (int i = 0; i <= n - 1; i++) {
        int temp;
        cin >> temp;
        seg1[arrsize + i] = temp;
        seg2[arrsize + i] = temp;
    }

    init1(arrsize, arrsize * 2 - 1, 1);
    init2(arrsize, arrsize * 2 - 1, 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << submin(arrsize, arrsize * 2 - 1, 1, arrsize - 1 + a, arrsize - 1 + b) << ' ' << \
            submax(arrsize, arrsize * 2 - 1, 1, arrsize - 1 + a, arrsize - 1 + b) << '\n';
    }

}