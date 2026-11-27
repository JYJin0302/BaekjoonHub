#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> lst;
int lim = 1;
int track[15];

void cal() {

    vector<int> tmp;
    for (int i = 0; i < lim; i++) tmp.push_back(track[i]);

    if (tmp[0] == 0) {
        if (lim == 1) return;
        swap(tmp[0], tmp[1]);
    }

    do {
        int res = 0;
        for (auto f : tmp) res = res * 10 + f;
        lst.push_back(res);
    } while (next_permutation(all(tmp)));

}

void choose(int cnt, int pv = 0) {
    if (cnt == lim) {
        cal();
        return;
    }

    for (int i = pv; i <= 9; i++) {
        track[cnt] = i;
        choose(cnt + 1, i + 1);
    }
}

void solve() {

    for (lim = 1; lim <= 8; lim++) {
        choose(0);
    }

    sort(all(lst));

    int n;
    cin >> n;
    while (n) {
        cout << lst[n - 1] << '\n';
        cin >> n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}