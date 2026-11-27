#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll ccw(pair<ll, ll> p1, pair<ll, ll> p2){
    ll res = p1.x * p2.y - p2.x * p1.y;
    if (res) res /= abs(res);
    return res;
}
ll dot(pair<ll, ll> p1, pair<ll, ll> p2){
    ll res = p1.x * p2.x + p2.y * p1.y;
    if (res) res /= abs(res);
    return res;
}
pair<ll, ll> operator-(pair<ll, ll> p1, pair<ll, ll>p2){
    return mp(p1.x - p2.x, p1.y - p2.y);
}

void solve(){
    
    ll ax1, ax2, ay1, ay2, bx1, bx2, by1, by2, vx, vy;
    cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2 >> vx >> vy;

    pair<ll, ll> Pa1 = mp(ax1, ay1);
    pair<ll, ll> Pa2 = mp(ax2, ay2);
    pair<ll, ll> Pb1 = mp(bx1, by1);
    pair<ll, ll> Pb2 = mp(bx2, by2);
    pair<ll, ll> V = mp(vx, vy);


    for(auto p1 : {Pa1, Pa2}){
        for(auto p2 : {Pb1, Pb2}){
            if (ccw(p2 - p1, V) == 0 && dot(p2-p1, V) > 0){
                cout << "Yes\n";
                return;
            }
        }
    }

    // a1 -> b1, b2

    for(auto p1 : {Pa1, Pa2}){
        ll c1 = ccw(V, Pb1- p1), c2 = ccw(V, Pb2 - p1);
        pair<ll, ll> p2 = p1;

        ll mul = 1e9;
        if(V.x != 0){
            if (V.x < 0){
                mul = min(mul, (-(ll)1e7 - p1.x) / V.x);
            }
            else{
                mul = min(mul, ((ll)1e7 - p1.x) / V.x);
            }
        }
        if (V.y != 0){
            if (V.y < 0){
                mul = min(mul, (-(ll)1e7 - p1.y) / V.y);
            }
            else{
                mul = min(mul, ((ll)1e7 - p1.y) / V.y);
            }
        }

        p2.x += mul * V.x;
        p2.y += mul * V.y;


        pair<ll, ll> V2 = Pb2 - Pb1;
        if(c1 * c2 < 0){
            ll tc1 = ccw(V2, p1-Pb1);
            ll tc2 = ccw(V2, p2 - Pb1);
            if (tc1 * tc2 < 0){
                cout << "Yes\n";
                return;
            }
        }
    }

    // swap
    swap(Pa1, Pb1);
    swap(Pa2, Pb2);
    V.x *= -1, V.y *= -1;for(auto p1 : {Pa1, Pa2}){
        ll c1 = ccw(V, Pb1- p1), c2 = ccw(V, Pb2 - p1);
        pair<ll, ll> p2 = p1;

        ll mul = 1e9;
        if(V.x != 0){
            if (V.x < 0){
                mul = min(mul, (-(ll)1e7 - p1.x) / V.x);
            }
            else{
                mul = min(mul, ((ll)1e7 - p1.x) / V.x);
            }
        }
        if (V.y != 0){
            if (V.y < 0){
                mul = min(mul, (-(ll)1e7 - p1.y) / V.y);
            }
            else{
                mul = min(mul, ((ll)1e7 - p1.y) / V.y);
            }
        }

        p2.x += mul * V.x;
        p2.y += mul * V.y;


        pair<ll, ll> V2 = Pb2 - Pb1;
        if(c1 * c2 < 0){
            ll tc1 = ccw(V2, p1-Pb1);
            ll tc2 = ccw(V2, p2 - Pb1);
            if (tc1 * tc2 < 0){
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
    return;


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

