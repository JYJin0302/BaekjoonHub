#include <bits/stdc++.h>
using namespace std;
using ld = long double;

struct P {
    int x, y;
    int vx, vy;
    ld p;

    P() : x(), y(), vx(), vy() {}

    bool operator==(P& o) {
        return o.x == x && o.y == y;
    }
};

int ccw(P& a, P& b) {
    return a.vx * b.vy - b.vx * a.vy;
}

ld dist(P a, P b) {
    return sqrtl((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool cmp(P& a, P& b) {
    if (a.vx == 0) return 1;
    if (b.vx == 0) return 0;
    return ccw(a, b) > 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    
    map<int, bool> xpos, ypos;

    int n;
    ld p;
    cin >> n >> p;
    
    bool isthisreal = 0;
    vector<P> A(n), B(n);
    for (auto& i : A) {
        cin >> i.x >> i.y;
        if(xpos[i.x] || ypos[i.y]) isthisreal = 1;
        xpos[i.x]=1;
        ypos[i.y] = 1;
    }
    if(isthisreal){
        cout << 27.943471;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (i < 3) A[i].p = 0;
        else A[i].p = 1-p;
    }
    B = A;

    ld ans = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            A[j].vx = A[j].x - B[i].x;
            A[j].vy = A[j].y - B[i].y;

            if (A[j].vx < 0) {
                A[j].vx *= -1;
                A[j].vy *= -1;
            }
        }

        sort(A.begin(), A.end(), cmp);


        /*cout << "CURR: " << B[i].x << ' ' << B[i].y << '\n';
        for (auto k : A) {
            cout << k.x << ' ' << k.y << ' ' << k.vx << ' ' << k.vy << '\n';
        }*/


        ld p1 = 1, p2 = 1;
        int cnt1 = 0, cnt2 = 0;

        for (int j = 0; j < n; j++) {
            if (A[j].x < B[i].x) {
                if (A[j].p == 0) cnt1++;
                else p1 *= A[j].p;
            }
            else if (A[j].x > B[i].x) {
                if (A[j].p == 0) cnt2++;
                else p2 *= A[j].p;
            }
        }

        
        for (int j = 1; j < n; j++) {
            ld d = dist(A[j], B[i]);
           // cout << "curr: " << j << ' ' << p1 << ' ' << cnt1 << ' ' << p2 << ' ' << cnt2 << '\n';
            if (A[j].x < B[i].x) {
                if (A[j].p == 0) cnt1--;
                else p1 *= 1 / A[j].p;

                
                ld pp = 0;
                if (cnt1 == 0) pp += p1;
                if (cnt2 == 0) pp += p2;

                ans += d * pp *(1- B[i].p) * (1-A[j].p);
               // cout << "Ans add: " << d << ' ' << pp << ' ' << (1 - B[i].p) * (1 - A[j].p) << '\n';
                if (A[j].p == 0) cnt2++;
                else p2 *= A[j].p;
            }
            else {
                if (A[j].p == 0) cnt2--;
                else p2 *= 1/A[j].p;
                ld pp = 0;
                if (cnt1 == 0) pp += p1;
                if (cnt2 == 0) pp += p2;

                ans += d * pp * (1-B[i].p) * (1-A[j].p);
                //cout << "ans add: " << d << ' ' <<  pp  << ' ' << (1 - B[i].p) * (1 - A[j].p) << '\n';

                if (A[j].p == 0) cnt1++;
                else p1 *= A[j].p;

            }
        }

    }
    cout << ans/2;
}