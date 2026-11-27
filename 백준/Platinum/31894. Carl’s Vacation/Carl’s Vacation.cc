#include <bits/stdc++.h>
using namespace std;
using ld = long double;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define mp make_pair

ld dist(pair<ld, ld>& p1,pair<ld, ld>& p2){
    return sqrtl((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

ll h1, h2;
ld cx1 = 0, cx2 = 0, cy1 = 0, cy2 = 0;
vector<pair<ld, ld>> P1, P2;

ld getDist(pair<ld, ld>& p1, pair<ld, ld>& p2){
    ld res = 0;
    pair<ld, ld> cen1 = mp(cx1, cy1);
    ld v = dist(p1, cen1);
    res += sqrtl(v*v + h1*h1);
    res += dist(p1, p2);
    pair<ld, ld> cen2 = mp(cx2, cy2);
    v = dist(p2, cen2);
    res += sqrtl(v*v + h2*h2);
    return res;
}

void solve(){

    ll x1, x2, y1, y2, h;
    cin >> x1 >> y1 >> x2 >> y2 >> h;

    h1 = h;
    ll px = x1, py = y1;
    ll dx = x2 - x1, dy = y2 - y1;
    P1.push_back(mp(x1, y1));
    for(int i = 0; i < 3; i++){
        px += dx;
        py += dy;
        P1.push_back(mp(px, py));
        swap(dx, dy);
        dx *= -1;
    }

    cin >> x1 >> y1 >> x2 >> y2 >> h;
    h2 = h;
    px = x1, py = y1;
    dx = x2 - x1, dy = y2 - y1;
    P2.push_back(mp(x1, y1));
    for(int i = 0; i < 3; i++){
        px += dx;
        py += dy;
        P2.push_back(mp(px, py));
        swap(dx, dy);
        dx *= -1;
    }

    // pair<ld,ld> tmp = {0,0};
    // pair<ld,ld> tmp2 = {9,18};
    // cout<<getDist(tmp,tmp2)<<endl;

    for(auto[a,b] : P1){
        cx1 += a;
        cy1 += b;
    }
    cx1 /= 4; cy1 /= 4;
    for(auto[a,b] : P2){
        cx2 += a;
        cy2 += b;
    }
    cx2 /= 4, cy2 /= 4;

    ld ans = 1e18;
    for(int i = 0; i < 4; i++){
        int pi = (i+3) % 4;
        for(int j = 0; j < 4; j++){
            int pj = (j+3) % 4;

            ld l,r,q1,q2;
            l=0;r=1;
            const ld eps = 1e-8;
            auto F=[&](ld m){
                ld ret = 0;

                pair<ld,ld> aa;
                aa.first = (P1[i].x*m + (1-m)*P1[pi].x);
                aa.second = (P1[i].y*m + (1-m)*P1[pi].y);

                ld l,r,q1,q2;
                l=0;r=1;
                auto G=[&](ld n){
                    pair<ld,ld> bb;
                    bb.first = (P2[j].x*n + (1-n)*P2[pj].x);
                    bb.second = (P2[j].y*n + (1-n)*P2[pj].y);

                    return getDist(aa,bb);
                };

                while(r>l+eps){
                    q1 = (2*l+r)/3;
                    q2 = (l+2*r)/3;

                    ld v1,v2;
                    v1 = G(q1);
                    v2 = G(q2);
                    if (v1 > v2){
                        l=q1;
                    }else{
                        r=q2;
                    }
                }
                ret = G(l);
                return ret;
            };

            while(r>l+eps){
                q1 = (2*l+r)/3;
                q2 = (l+2*r)/3;
                ld v1,v2;
                v1 = F(q1);
                v2 = F(q2);
                if (v1 > v2){
                    l = q1;
                }else{
                    r = q2;
                }
            }

            ld cur = F(l);
            ans = min(ans,cur);
        }
    }

    cout << fixed << setprecision(10);
    cout << ans << '\n';


}


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}