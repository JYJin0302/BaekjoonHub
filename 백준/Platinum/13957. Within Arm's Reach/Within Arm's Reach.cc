#include<bits/stdc++.h>
#define ll long long
using namespace std;
using ld = long double;

ld dist(ld x1, ld x2, ld y1, ld y2) {
    return sqrtl((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
}

ld PI = acos(-1); 

pair<ld, ld> moveA(ld x, ld y, ld angle) {
    // x, y 를 angle 만큼 각이동
    ld nx = cos(angle) * x - sin(angle) * y;
    ld ny = sin(angle) * x + cos(angle) * y;
    return { nx, ny };
}

int n;
int A[22];
ld tx, ty;

vector<pair<ld, ld>> ans;
pair<ld, ld> target[22];
bool solve(int ix, ld l, ld r) {
    // l, r 도달 가능한 범위
    // tx, ty 타겟 좌표
    // ix 인덱스
    
    if (ix == n) {
        ld d1 = dist(0, 0, target[n].first, target[n].second);

        if (d1 <= r && d1 >= l) return 1;
        return 0;
    }

    int len = A[ix];
    ld nr = r + len;
    ld nl;
    if (len <= l) nl = l - len;
    else if (len <= r) nl = 0;
    else {
        nl = len - r;
    }
    
    if (solve(ix + 1, nl, nr)) {

        ld nx, ny;
        tie(nx, ny) = target[ix + 1];

        ld d1 = dist(0, 0, nx, ny);
        ld d2 = A[ix];
        ld validL = abs(d1 - d2);
        ld validR = d1 + d2;

        ld d3;
        if (validL <= l+1e-6 && l <= validR + 1e-6) d3 = l;
        else if (validL <= r+1e-6 && r <= validR+1e-6) d3 = r;
        else d3 = validL;
  
        if (d1 != 0) {

            ld newX = d3 * d3 - d2 * d2 + d1 * d1;
            newX /= 2 * d1;
            ld newY;
            if (d3*d3 >= newX*newX) newY = sqrtl(d3 * d3 - newX * newX);
            else newY = 0;

            ld currAngle = 0;
            if (ny >= 0) currAngle = acos(nx / d1);
            else currAngle = PI + acos(-nx / d1);

            tie(newX, newY) = moveA(newX, newY, currAngle);
            target[ix] = { newX, newY };
        }
        else {
            target[ix] = { d3, 0 };
        }
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> tx >> ty;
    target[n] = { tx, ty };

    ld d1 = dist(0, 0, tx, ty), angle = 0;
    if (d1 != 0) {
        if (ty >= 0) {
            angle = acos(tx / d1);
        }
        else {
            angle = acos(-tx / d1) + PI;
        }
    }

    if (solve(0, 0, 0)) {
        for (int i = 1; i <= n; i++) {
            cout << target[i].first << ' ' << target[i].second << '\n';
        }
        return 0;
    }
    
    vector<pair<ld, ld>> ans;
    int ansi = -1;
    ld ansval = 1e15;
    for (int i = 0; i < (1 << n); i++) {

        ld res = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) res += A[j];
            else res -= A[j];
        }

        if (abs(res - d1) < ansval) {
            ansval = abs(res - d1);
            ansi = i;
        }
    }

    ld px = 0, py = 0;
    for (int i = 0; i < n; i++) {
        if (ansi & (1 << i)) {
            px += A[i];
        }
        else px -= A[i];
        ans.push_back({ px, py });
    }
    for (auto& i : ans) {
        if (d1 != 0) i = moveA(i.first, i.second, angle);
    }
    for (auto i : ans)cout << i.first << ' ' << i.second << '\n';
}
