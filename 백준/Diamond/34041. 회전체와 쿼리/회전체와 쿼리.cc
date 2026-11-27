#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b% a, a);
}
struct P{
    ll x, y;

    ll cross(P p) const {return x*p.y-y*p.x;}
};

ld getDist(ll a, ll b, ll c, ld cx, ld cy){
    ld res = abs(a * cx + b *cy + c);
    return 1.0 * res / sqrtl(a*a + b*b);
}

const ld PI = acos(-1);

ll val[101010], valX[101010], valY[101010];

void solve(){

    int n;
    cin >> n;

    cout << setprecision(15);

    vector<P> A(n);
    for(int i =0 ; i < n; i++){
        cin >> A[i].x >> A[i].y;
    }

    for(int i = 0; i < n;i++){
        int ni = (i+1) % n;
        val[i] = A[i].cross(A[ni]);
        valX[i] = (A[i].x + A[ni].x) * val[i];
        valY[i] = (A[i].y + A[ni].y) * val[i];

        if (i) {
            val[i] += val[i-1];
            valX[i] += valX[i-1];
            valY[i] += valY[i-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a>> b;
        a--, b--;
        if (a > b) swap(a, b);

        if (b == a + 1 || b == a + n-1){
            cout << 0 << '\n';
            continue;
        }

        ld cx, cy; // center of mass
        ll area;
        ld dist, ans1, ans2;


        // get Line
        ll ta = A[a].y - A[b].y;
        ll tb = A[b].x - A[a].x;
        ll tc = A[a].cross(A[b]);

        ll g = gcd(gcd(ta, tb), tc);
        ta /= g, tb /= g, tc /= g;

        // a ~ b
        area = val[b - 1] - (a > 0 ? val[a-1] : 0);
        area += A[b].cross(A[a]);

        if (area == 0) ans1 = 0;
        else{
            cx = valX[b-1] - (a > 0 ? valX[a-1] : 0);
            cx += (A[b].x + A[a].x) * A[b].cross(A[a]);

            cy = valY[b-1] - (a > 0 ? valY[a-1] : 0);
            cy += (A[b].y + A[a].y) * A[b].cross(A[a]);

            cx /= 3*area;
            cy /= 3*area;
            dist = getDist(ta, tb, tc, cx, cy);

            ans1 = dist * area; 
        }

        // b ~ n-1 + 0 ~ a
        area = (a ? val[a - 1] : 0) + val[n-1] - val[b-1];
        area += A[a].cross(A[b]);

        if (area == 0) ans2 = 0;
        else {
            cx = (a ? valX[a-1] : 0) + valX[n-1] - valX[b-1];
            cx += (A[b].x + A[a].x) * A[a].cross(A[b]);
            
            cy = (a ? valY[a-1] : 0) + valY[n-1] - valY[b-1];
            cy += (A[b].y + A[a].y) * A[a].cross(A[b]);

            cx /= 3*area;
            cy /= 3*area;
            
            dist = getDist(ta, tb, tc, cx, cy);

            ans2 = dist * area;
        }

        cout << min(ans1, ans2) * PI << '\n';
    }

    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}