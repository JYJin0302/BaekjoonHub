#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll gcd(ll a, ll b){
    if (a > b) swap(a, b);
    return a ? gcd(a, b%a) : b;
}

int target[] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};

int a1, a2,b1,b2,b3,c1,c2,d1,e1;
int s, n;

struct rnum{
    ll x, y;
    rnum(ll x = 0, ll y = 1): x(x), y(y) {
        if (x != -1){
            ll g = gcd(x, y);
            this->x /= g;
            this->y /= g;
        }
    }
    rnum operator+(const rnum& r) const { return rnum(x*r.y+y*r.x , y*r.y); }
    rnum operator*(const rnum& r) const { return rnum(x*r.x, y*r.y); }
    bool operator<(const rnum& r) const { return x*r.y < y*r.x; }
    bool operator==(const rnum& r) const { return x *r.y == y* r.x; }
};

rnum P[4][200]; // P[a][b] : 다트 a개 남고 점수 b점 남을 때의 최대 확률
string mv[4][200]; // mv[a][b] : 다트 a개 남고 점수 b점 남을 때의 최대 확률을 만들기 위한 이동

rnum goSolve(int n, int s, bool isDouble = 0){
    if (s == 0 && isDouble) return rnum(1, 1);
    if (s <= 0 || n == 0) return rnum(0, 1);
    if(P[n][s].x != -1) return P[n][s];


    P[n][s] = rnum(0, 1);
    mv[n][s] = "";

    for(int i = 0; i < 20; i++){
        // target = target[i]
        int x = target[(i+19)%20];
        int y = target[i];
        int z = target[(i+1)%20];

        // try triple
        rnum prob = rnum(0, 1);
        prob = prob + rnum(a1, 100) * goSolve(n-1, s - 3*y);
        prob = prob + rnum(a2, 100) * goSolve(n-1, s - 3*x);
        prob = prob + rnum(a2, 100) * goSolve(n-1, s - 3*z);
        prob = prob + rnum(100 - a1 - 2*a2, 100) * goSolve(n-1, s - y);
        if (P[n][s] < prob || P[n][s] == prob && mv[n][s] > "Triple " + to_string(y)) {
            P[n][s] = prob;
            mv[n][s] = "Triple " + to_string(y);
        }

        // try double
        prob = rnum(0, 1);
        prob = prob + rnum(b1, 100) * goSolve(n-1, s - 2*y, 1);
        prob = prob + rnum(b2, 100) * goSolve(n-1, s - 2*x, 1);
        prob = prob + rnum(b2, 100) * goSolve(n-1, s - 2*z, 1);
        prob = prob + rnum(b3, 100) * goSolve(n-1, s - y);
        prob = prob + rnum(100 - b1 - 2*b2 - b3, 100) * goSolve(n-1, s);
        if (P[n][s] < prob || P[n][s] == prob && mv[n][s] > "Double " + to_string(y)) {
            P[n][s] = prob;
            mv[n][s] = "Double " + to_string(y);
        }

        // try single
        prob = rnum(0, 1);
        prob = prob + rnum(c1, 100) * goSolve(n-1, s - y);
        prob = prob + rnum(c2, 100) * goSolve(n-1, s - x);
        prob = prob + rnum(c2, 100) * goSolve(n-1, s - z);
        prob = prob + rnum(100 - c1 - 2*c2, 100) * goSolve(n-1, s - 2*y, 1);
        if (P[n][s] < prob || P[n][s] == prob && mv[n][s] > "Single " + to_string(y)) {
            P[n][s] = prob;
            mv[n][s] = "Single " + to_string(y);
        }
    }   


    // try bull
    rnum prob = rnum(0, 1);
    prob = prob + rnum(d1, 100) * goSolve(n-1, s - 25);
    prob = prob + rnum(100 - d1, 100) * goSolve(n-1, s - 50, 1);
    if (P[n][s] < prob || P[n][s] == prob && mv[n][s] > "Single Bull") {
        P[n][s] = prob;
        mv[n][s] = "Single Bull";
    }

    // try double bull
    prob = rnum(0, 1);
    prob = prob + rnum(e1, 100) * goSolve(n-1, s - 50, 1);  
    prob = prob + rnum(100 - e1, 100) * goSolve(n-1, s - 25);
    if (P[n][s] < prob || P[n][s] == prob && mv[n][s] > "Double Bull") {
        P[n][s] = prob;
        mv[n][s] = "Double Bull";
    }
    return P[n][s];
}

void solve() {
    cin >> s >> n;
    goSolve(n, s);
    
    //cout << "solved : " << n << " " << s << " " << P[n][s].x << "/" << P[n][s].y << " | " << 100.0 * P[n][s].x/P[n][s].y << "\n";
    if (P[n][s].x == 0){
        cout << "Impossible\n";
    } 
    else {
        cout << mv[n][s] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //init
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 200; j++){
            P[i][j] = rnum(-1, 1);
            mv[i][j] = "";
        }
    }

    int t = 1;
    cin >> t;
    cin >> a1 >> a2 >> b1 >> b2 >> b3 >> c1 >> c2 >> d1 >> e1;
    while (t--) solve();
}