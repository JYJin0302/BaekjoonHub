#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int baseG;
int curF;
struct Player {
    ll xpos = 0, ypos = 0;
    ll velX = 0, velY = 0;
    int baseX = 0;
    int jump = 0;
    int dash = 0;
    bool quick = 0;
    bool accel = 0;
    bool weak = 0;
    bool spin = 0;
    int maxdrop = 0;
    bool motion = 0;
    bool xychain = 0;
    int endAcc = -1;
    int endGW = -1;
    int endMotion = -1;
    int spinCnt = 0;
    void d() {
        dash = 10;
        velY = 0;
    }
    void aj() {
        velY = jump;
    }
    void qd() {
        quick = 1;
        velY = -maxdrop;
    }
    void ra() {
        spin = 1;
        spinCnt++;
    }
    void hda() {
        dash = 10;
        velY = 0;
    }
    void ruda() {
        dash = 10;
        xychain = 1;
    }
    void acc() {
        accel = 1;
        endAcc = curF + 600;
    }
    void gw() {
        weak = 1;
        endGW = curF + 600;
    }
    void bomb() {
        velY = 0;
        motion = 1;
        endMotion = curF + 100;
    }
    void shield() {
        velY = 0;
        motion = 1;
        endMotion = curF + 30;
    }
    void potion() {
        velY = 0;
        motion = 1;
        endMotion = curF + 150;
    }
    void none() {}


    void action(string inp) {
        if (inp == "d") d();
        else if (inp == "aj") aj();
        else if (inp == "qd") qd();
        else if (inp == "ra") ra();
        else if (inp == "hda") hda();
        else if (inp == "ruda") ruda();
        else if (inp == "acc") acc();
        else if (inp == "gw") gw();
        else if (inp == "bomb") bomb();
        else if (inp == "shield") shield();
        else if (inp == "potion") potion();
        else none();
    }

    void state() {
        cout << "Current pos: " << xpos << ' ' << ypos << " | " << velX << ' ' << velY << '\n';
    }
};

void solve() {

    Player p;
    cin >> p.baseX >> p.jump >> p.maxdrop;
    cin >> baseG >> p.ypos;
    p.velY = p.jump;

    int n;
    cin >> n;

    string inp;
    curF = 0;

   // cout << "Curf: " << curF << " => ";
  //  p.state();
    for (curF = 1; ; curF++) {
        if (curF <= n) cin >> inp;
        else inp = "none";

        if (curF > n + 1000 && p.velY == -p.maxdrop) {
            // simulate to end
            ll t = (p.ypos + p.maxdrop - 1) / p.maxdrop;
            p.xpos += t * p.velX;
            p.ypos = 0;
            curF += t;
        }

        if (p.ypos == 0 && !p.spin) {
            cout << p.xpos << '\n';
            return;
        }

        if (p.ypos == 0 && p.spin) {
            p.spin = 0;
            p.velY *= -1;
        }
        p.dash = max(0, p.dash - 1);
        if (p.dash == 0) p.xychain = 0;

        if (curF == p.endAcc) {
            p.endAcc = -1;
            p.accel = 0;
        }
        if (curF == p.endGW) {
            p.endGW = -1;
            p.weak = 0;
        }
        if (curF == p.endMotion) {
            p.endMotion = -1;
            p.motion = 0;
        }

        if (p.dash == 0 && !p.motion && (p.spinCnt != 1 || inp != "ra")) {
            p.action(inp);
            if (inp != "ra" && inp != "none") p.spin = 0;
            if (inp == "d" || inp == "hda" || inp == "ruda" || inp == "bomb" || inp == "potion" || inp == "shield") p.quick = 0;
        }

        p.velX = 1ll * (1ll + (p.dash+1)/2 + 5 * p.quick) * (1ll + p.accel) * p.baseX * (1ll - p.motion);
        p.xpos += p.velX;

        if (p.xychain) p.velY = p.velX;
        p.ypos = max(0ll, p.ypos + p.velY);


        if (p.dash == 0 && !p.motion) p.velY = max(-(ll)p.maxdrop, p.velY - baseG / (1 + p.weak));

       // cout << "Curf: " << curF << " => ";
       // p.state();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
