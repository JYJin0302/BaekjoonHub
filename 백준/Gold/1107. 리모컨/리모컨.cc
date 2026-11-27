#include <bits/stdc++.h>
using namespace std;

int maxim;
string s;
int target;
int ans;
bool button[10];

void bf(int cnt = 0, int te = 0) {

    if (cnt == maxim) {

        ans = min(ans, cnt + abs(te - target));
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (button[i]) continue;
        bf(cnt + 1, te * 10 + i);
    }

}


int main() {

    cin >> s;
    int size = s.size();
    target = stoi(s);
    int b, a;
    cin >> b;
    while (b--) {
        cin >> a;
        button[a] = 1;
    }

    ans = abs(100 - target);

    for (maxim = 1; maxim <= 7; maxim++) {
        bf();
    }


    cout << ans;

}