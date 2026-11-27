#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int base[4];
int s[4];

int winn(int l, int r) {
    if (base[l] == base[r] || base[r] == (base[l] + 1) % 3) return l;
    return r;
}

vector<int> getres() {
    vector<int> res(4);
    res = { winn(s[0], s[1]), winn(s[2], s[3]), s[0] + s[1] - winn(s[0], s[1]), s[2] + s[3] - winn(s[2], s[3]) };
    if (winn(res[0], res[1]) == res[1]) swap(res[0], res[1]);
    if (winn(res[2], res[3]) == res[3]) swap(res[2], res[3]);
    return res;
}


int getIdx(vector<int>& v, vector<int>& v2) {
    int res = 0;
    for (int i = 0; i < 4; i++) res = res * 4 + v[i];
    for (int i = 0; i < 4; i++) res = res * 4 + v2[i];
    return res;
}

vector<int> re(vector<int> v) {
    vector<int> res = v;
    sort(all(v));
    for (auto& i : res) i = lower_bound(all(v), i) - v.begin();
    return res;
}

vector<vector<int>> st[1001010];

int res[101010];

int n, sN;

void getRes(int d) {
    int l = 1;
    while (l <= sN) {
        vector<int> toAsk(4);

        bool two = 0;
        if (l + 3 * d <= sN) {
            // update
            for (int i = 0; i < 4; i++) toAsk[i] = l + i * d;
        }
        else {
            // 마지막 인 것
            two = 1;
            toAsk = { 1, 2, sN - 1, sN };
        }
        cout << "? ";
        for (auto f : toAsk) cout << f << ' ';
        cout << endl;
        vector<int> tmp(4);
        for (auto& i : tmp) cin >> i;
        vector<int> t1 = re(tmp);

        reverse(all(toAsk));
        cout << "? ";
        for (auto f : toAsk) cout << f << ' ';
        cout << endl;
        reverse(all(toAsk));
        for (auto& i : tmp) cin >> i;
        vector<int> t2 = re(tmp);

        int idx = getIdx(t1, t2);
        vector<int> rel = st[idx][0];

        /*cout << "Get res: ";
        for (auto f : rel) cout << f << ' ';
        cout << '\n';*/
        // update


        if (!two) {
            for (int i = 1; i < 4; i++) {
                int pos = l + i * d;
                // pos - pos + d - 1
                int curDif = (res[pos] - res[l] + 3) % 3;
                int newDif = (rel[i] - rel[0] + 3) % 3;

                int dif = (newDif - curDif + 3) % 3;
                for (int j = pos; j < pos + d; j++) {
                    (res[j] += dif) %= 3;
                }
            }
        }
        else {
            int pos = l + d;
            int curDif = (res[pos] - res[l] + 3) % 3;
            int newDif = (rel[2] - rel[0] + 3) % 3;
            int dif = (newDif - curDif + 3) % 3;
            for (int j = l + d; j <= sN; j++) {
                (res[j] += dif) %= 3;
            }
        }

        l += 4 * d;
    }

}

void solve() {

    for (int i = 0; i < 3; i++) {
        base[0] = i;
        for (int j = 0; j < 3; j++) {
            base[1] = j;
            for (int k = 0; k < 3; k++) {
                base[2] = k;
                for (int w = 0; w < 3; w++) {
                    base[3] = w;
                    for (int f = 0; f < 4; f++) s[f] = f;
                    vector<int> v1 = getres();
                    for (int f = 0; f < 4; f++) s[3 - f] = f;
                    vector<int> v2 = getres();
                    int val = getIdx(v1, v2);
                    vector<int> tmp = { base[0], base[1], base[2] ,base[3] };
                    st[val].push_back(tmp);
                }
            }
        }
    }

    int k;
    cin >> n >> k;
    sN = 1 << n;

    int d = 1;
    while (d < sN) {
        //cout << "Go: " << d << '\n';
        getRes(d);
        d <<= 2;
    }

    vector<int> cnt(3);
    for (int i = 1; i <= sN; i++) {
        cnt[res[i]]++;
    }

    int c0 = cnt[res[k]];
    int c1 = cnt[(res[k] + 1) % 3];
    int c2 = cnt[(res[k] + 2) % 3];

    //cout << c0 << ' ' << c1 << ' ' << c2 << '\n';

    int erz = sN >> 1;
    while (c1 > 0 && c2 > 0) {
        c1--;
        c2 -= erz - 1;
        erz >>= 1;
    }

    if (c2 <= 0) cout << "! Y" << endl;
    else cout << "! N" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}