#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
bool ok = 1;
vector<int> cube;
vector<int> twos;
void solve(int x, int y, int z) {
    if (!(x && y && z)) return;

    for (int i = 20; i >= 0; i--) {
        if (cube[i] == 0) continue;

        int len = twos[i];
        if (min({ x,y,z }) >= len) {
            cube[i]--;
            cnt++;
            solve(x, y, z - len);
            solve(len, y - len, len);
            solve(x - len, len, len);
            solve(x - len, y - len, len);

            return;
        }
    }
    ok = 0;
}


int main() {

    int x, y, z;
    cin >> x >> y >> z;

    int n;
    cin >> n;

    twos = vector<int>(21);
    twos[0] = 1;
    for (int i = 1; i <= 20; i++) twos[i] = twos[i - 1] * 2;

    cube = vector<int>(21);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cube[a] = b;
    }

    solve(x, y, z);

    if (ok) cout << cnt;
    else cout << -1;
}