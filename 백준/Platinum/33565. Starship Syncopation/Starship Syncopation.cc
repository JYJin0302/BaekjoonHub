#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int n;
int MAXN = 1000010;
int seg[2002020];
void update(int ix, int val) {
    for (ix += MAXN; ix; ix >>= 1) {
        seg[ix] += val;
    }
}

int getVal(int l, int r) {
    int res = 0;
    for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

int enemy[1001010];
int enemyIdx = 0;


struct Starship {
    int starPow = 0;
    int prayCnt = 0;
    ll inDmg = 0;
    ll curDmg = 0;
    bool overload = 0;
    ll dmgL = 0, dmgR = 0;
    int destroyCnt = 0;

    void store() {
        
        starPow = min(1000000, starPow + 1 + prayCnt + destroyCnt);

        if (overload) {
            ll allDmg = starPow / 10;
            inDmg += allDmg;
            dmgL += allDmg;
            dmgR = max(dmgR, dmgL);
            starPow %= 10;
        }
    }

    void wait() {

    }

    void pray() {
        if (starPow < 7) {
            wait();
            return;
        }
        starPow -= 7;
        prayCnt++;
    }

    void repair() {
        if (starPow < 3) {
            wait();
            return;
        }
        int t = min(3ll, inDmg);
        inDmg -= t;
        starPow -= t;
    }

    void sync() {
        if (overload) {
            starPow = 0;
            inDmg += 5;
            overload = 0;
            return;
        }

        curDmg += starPow;
        starPow = 0;
        overload = 1;
    }
    void laser() {
        if (overload) {
            if (starPow >= 6) {
                dmgL += starPow;
                dmgR = max(dmgR, dmgL);
            }
            else {
                inDmg += 5;
            }
            starPow = 0;
            overload = 0;
            return;
        }

        if (starPow < 5) sync();
        else {
            starPow -= 5;
            curDmg += 5;
        }
    }

    void enemyAct() {
        // 침몰 수 구하기
        while (enemyIdx < n && max(curDmg + dmgL, dmgR) >= enemy[enemyIdx]) {
            curDmg = 0;
            update(enemy[enemyIdx], -1);
            enemyIdx++;
        }
        int tmp = enemyIdx;
        tmp += getVal(0, min(1000000ll, dmgR) + 1);
        destroyCnt = tmp;

        if (dmgL > 0) {
            dmgL--;
        }
        else {
            inDmg += n - destroyCnt - (curDmg > 0);
            if (curDmg > 0) curDmg--;
        }
    }

    void pf() {
        cout << inDmg << ' ' << starPow << ' ' << n - destroyCnt << '\n';
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> enemy[i];
        update(enemy[i], 1);
    }

    int t;
    cin >> t;
    string s;
    cin >> s;

    int q;
    cin >> q;
    queue<int> qLst;
    while (q--) {
        int ix;
        cin >> ix;
        qLst.push(ix);
    }

    Starship ss;

    for (int i = 0; i < t; i++) {
        char c = s[i];

        ss.store();
        if (c == 'W') ss.wait();
        else if (c == 'R') ss.repair();
        else if (c == 'P') ss.pray();
        else if (c == 'L') ss.laser();
        else if (c == 'S') ss.sync();

        ss.enemyAct();

        //ss.pf();
        if (!qLst.empty() && qLst.front() == i + 1) {
            qLst.pop();
            ss.pf();
        }

        if (ss.destroyCnt == n) break;
    }

    while (!qLst.empty()) {
        qLst.pop();
        cout << "skipped\n";
    }

}