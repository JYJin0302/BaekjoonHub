#include <bits/stdc++.h>
using namespace std;

string choose;
int n, hp, ans = 1000;
vector<pair<int, int>> spell;

void play() {

    int res = 0;
    int thp = hp;

    vector<int> spellcnt(n);
    for (int i = 0; i < 10; i++) {

        int s = choose[i] - '0';
        if (spellcnt[s] == 0) {
            res++;
            thp -= spell[s].second;
            spellcnt[s] = res;
        }
        else {
            res = max(res + 1, spellcnt[s] + spell[s].first);
            spellcnt[s] = res;
            thp -= spell[s].second;
        }

        if (thp <= 0)break;
    }
    ans = min(ans, res);
}

void select(int cnt = 0) {
    if (cnt == 10) {
        play();
        return;
    }

    for (int i = 0; i < n; i++) {
        choose[cnt] = i + '0';
        select(cnt + 1);
    }
}


int main() {

    cin >> n >> hp;

    choose = "0000000000";

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        spell.push_back({ a, b });
    }

    select();

    cout << ans;
}