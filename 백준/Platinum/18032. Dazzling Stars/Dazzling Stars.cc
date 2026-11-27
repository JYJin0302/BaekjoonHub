#include <bits/stdc++.h>
using namespace std;

struct Star {
    int x, y, b;

    bool operator<(Star& o) {
        return b > o.b;
    }
};


struct Vec {
    int vx, vy;

    bool operator<(Vec& o) {
        if ((vx < 0) != (o.vx < 0)) return vx < o.vx;
        return (vx * o.vy - vy * o.vx) > 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Star> A(n);
    for (auto& i : A) cin >> i.x >> i.y >> i.b;

    vector<Vec> tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i].b > A[j].b) {
                tmp.push_back({ A[i].x - A[j].x, A[i].y - A[j].y });
            }
        }
    }
    sort(tmp.begin(), tmp.end());
    

    n = tmp.size();
    if (n == 0) {
        cout << 'Y';
        return 0;
    }

    bool ok = 0;
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;

        int ccw = tmp[i].vx * tmp[ni].vy - tmp[i].vy * tmp[ni].vx;
        //cout << tmp[i].vx << ' ' << tmp[i].vy << " -> " << tmp[ni].vx << ' ' << tmp[ni].vy << '\n';
        
        if (ccw < 0) ok = 1;
        if (ccw == 0) {
            if (tmp[i].vx * tmp[ni].vx < 0) ok = 1;
            if (tmp[i].vy * tmp[ni].vy < 0) ok = 1;
        }
    }

    cout << (ok ? 'Y' : 'N');
}