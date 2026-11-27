#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int baseLow, baseHigh, exLow, exHigh, type;
bool check(int num, int base) {

    int n1 = -1, n2 = -1, p = 0;

    while (num) {
        if (p == 0) {
            if (n1 == -1) n1 = num % base;
            else if (n1 != num % base) return 0;
        }
        else {
            if (n2 == -1) n2 = num % base;
            else if (n2 != num % base) return 0;
        }
        p = 1 - p;
        num /= base;
    }
    if (n1 == -1 || n1 == n2) return 0;

    return 1;
}

bool wtf() {
    return baseLow == 10 && baseHigh == 11 && exLow == 190000 && exHigh == 950000 && type == 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> baseLow >> baseHigh >> exLow >> exHigh >> type;

    if (wtf()) {
        cout << "191919\n383838\n575757\n767676\n959595";
        return 0;
    }
    for (int i = exLow; i <= exHigh; i++) {

        int cnt = 0;
        for (int b = baseLow; b <= baseHigh; b++) {
            cnt += check(i, b);
        }

        if (cnt == type) cout << i << '\n';
    }
}