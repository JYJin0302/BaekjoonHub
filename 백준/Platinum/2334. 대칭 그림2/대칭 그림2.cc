#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
struct Point{
    ll x, y;
};

ll conv(string s){
    
    int idx, ts = s.size();
    for (idx = ts - 1; idx >= 0; idx--){
        if (s[idx] == '.') break;
    }
    
    if (idx == -1){
        s += "00";
    }
    else if (idx == ts - 1){
        s = s.substr(0, ts - 1) + "00";
    }
    else if(idx == ts - 2){
        s = s.substr(0, ts - 2) + s[ts-1] + '0';
    }
    else if (idx == ts - 3){
        s = s.substr(0, ts - 3) + s.substr(ts - 2, 2);
    }
    
    return stol(s);
}

ll GCD(ll a, ll b){
    if (b < a) swap(a, b);
    if (a == 0) return b;
    return GCD(b % a, a);
}

vector<Point> p;
map<pair<ll, ll>, bool> isP;

bool testP(int i, int j){
    
    // line : ax + by + c = 0
    // 두 점의 수직 이등분선 구하기
    ll a, b, c;
    
    Point mid = {(p[i].x + p[j].x)/2, (p[i].y + p[j].y) / 2};
    ll dx = p[j].x - p[i].x;
    ll dy = p[j].y - p[i].y;
    
    a = dx, b = dy;
    if (a == 0 && b == 0) return 0;
    
    ll gcd = GCD(abs(a), abs(b));
    a /= gcd, b /= gcd;
    
    c = -1 * (a * mid.x + b * mid.y);
    
    ll mod = a*a + b*b;
    
    // 모든 점들을 대칭이동 해본다
    for(int p1 = 0; p1 < n; p1++){
        
        ll tval = a * p[p1].x + b * p[p1].y + c, tmod = mod;
        
        ll temp = GCD(abs(tval), tmod);
        tval /= temp, tmod /= temp;
        
        if (2 * a % tmod != 0) return 0;
        if (2 * b % tmod != 0) return 0;
        
        ll x1 = p[p1].x - tval * (2 * a / tmod);
        ll y1 = p[p1].y - tval * (2 * b / tmod);
        
        if (x1 == p[p1].x && y1 == p[p1].y) return 0;
        if (!isP[{x1, y1}]) return 0;
    }
    
    
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        isP.clear();
        
        cin >> n;
        
        p = vector<Point>(n);
        for (auto& i : p) {
            string a, b;
            cin >> a >> b;
            i.x = conv(a) * 2;
            i.y = conv(b) * 2;
            isP[{i.x, i.y}] = 1;
        }

        bool ok = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                // 점 두 개 선택 -> 접어본다
                if(testP(i, j)){
                    ok = 1;
                }
            }
        }
        
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}