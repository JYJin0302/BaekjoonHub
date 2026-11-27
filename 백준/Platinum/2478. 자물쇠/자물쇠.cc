#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n;
int A[555];

pair<int, int> ans[5];

void getAns(int l, int r, int s = 0, int phase = 0) {
   // cout << "vis: " << l << ' ' << r << ' ' << s << ' ' << phase << '\n';
    if (phase == 2) {
        if (A[s] == 1) return;
        cout << A[s] - 1 << '\n' << ans[1].first+1 << ' ' << ans[1].second+1 << '\n' << ans[0].first << '\n';


        //vector<int> tmp(n);
        //for (int i = 0; i < n; i++) tmp[i] = i + 1;
        //for (auto f : tmp)cout << f << ' ';
        //cout << '\n';
        //for (int j = 0; j < A[s - 1]; j++) {
        //    for (int k = 0; k < n - 1; k++) swap(tmp[k], tmp[k + 1]);
        //}
        //for (auto f : tmp)cout << f << ' ';
        //cout << '\n';
        //int l = ans[1].first, r = ans[1].second;
        //while (l < r) {
        //    swap(tmp[l], tmp[r]);
        //    l++, r--;
        //}for (auto f : tmp)cout << f << ' ';
        //cout << '\n';
        //for (int j = 0; j < ans[0].first; j++) {
        //    for (int k = 0; k < n - 1; k++) swap(tmp[k], tmp[k + 1]);
        //}for (auto f : tmp)cout << f << ' ';
        //cout << '\n';

        exit(0);
    }

    if (phase == 0) {
        for (int k = 1; k < n; k++) {
            ans[phase].first = k;
            if (l == 0 && r == n - 1) getAns(l, r, (s - k + n) % n, phase + 1);
            else getAns((l+k)%n, (r+k)%n, (s - k + n) % n, phase + 1);
        }
        return;
    }

    if (l == 0 && r == n - 1) {
        ans[phase] = mp(l, r);
        getAns(l, r, n - s, phase + 1);
        return;
    }
    if (l > r) return;
    ans[phase] = mp(l, r);
    getAns(l, r, s, phase + 1);
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        int nx = (i + 1) % n;
        int nv = (A[i] + n - 2) % n + 1;

        if (A[nx] == nv) {
            l = i, r = i;
            while (1) {
                int nx = (i + 1) % n;
                if (nx == l) break;
                int nv = (A[i] + n - 2) % n + 1;
                if (A[nx] == nv) {
                    i = nx;
                    r = i;
                }
                else break;
            }
            break;
        }
    }
    
    while (1) {
        int pi = (l + n - 1) % n;
        if (pi == r) break;
        if (A[pi] == A[l] % n + 1) l = pi;
        else break;
    }

    int len = r - l + 1;
    if (len <= 0) len += n;

    int tl = l, tr = r;
    while (len > 1) {
        swap(A[tl], A[tr]);
        tl = (tl + 1) % n;
        tr = (tr + n - 1) % n;
        len -= 2;
    }


    getAns(l, r);
    assert(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}