#include <bits/stdc++.h>
using namespace std;


vector<int> base;

bool search(int l, int r, int item) {
    if (l == r) return item == base[l];
    int mid = (l + r) / 2;

    if (base[mid] == item) return true;

    if (base[mid] > item) return search(l, mid, item);
    else return search(mid + 1, r, item);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> n;
    base = vector<int>(n);
    for (auto& i : base) cin >> i;
    sort(base.begin(), base.end());


    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << search(0, n - 1, t) << ' ';
    }

}