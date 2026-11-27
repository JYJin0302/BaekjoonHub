#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


ld getY(array<int, 3> f, ld x){
    int a = f[0], b = f[1], c = f[2];
    ld res = x * x *a + x * b + c;
    //cout << a<< ' '<< b << ' ' << c << ' ' << x << " | " << res << '\n';
    return res;
}

pair<ld, ld> solve2(int a, int b, int c){
   // cout << "SOLVE@ : "<< a << ' '<< b << ' ' << c << " | ";
    ld v1 = 1.0 * (-b) / (2 * a);
    ld v2 = sqrtl(1.0 * b * b - 4 * a * c) / (2 * a);
    //cout <<v1 << ' '<< v2  << '\n';
    return mp(v1-v2, v1 + v2);
}

void solve(){
    
    int n;
    cin >> n;

    vector<array<int, 3>> pos, neg;
    for(int i =0; i < n; i++){
        int a, b, c;
        cin >> a>> b >> c;
        if (a > 0) pos.push_back({a, b, c});
        else neg.push_back({a, b, c});
    }

    cout << setprecision(16);
    if(pos.empty()){
        ld x = 0;
        ld y = neg[0][2];
        for(auto f : neg) y = min(y, (ld)f[2]);

        cout << x << ' '<< y - 1<< '\n';
        return;
    }
    if(neg.empty()){
        ld x = 0;
        ld y = pos[0][2];
        for(auto f : pos) y = max(y, (ld)f[2]);

        cout << x << ' '<< y  + 1<< '\n';
        return;
    }

   // cout << l1 << ' ' <<r1 << " | " << l2 << ' ' << r2 << '\n';

    ld xL = -1e15;
    ld xR = 1e15;
    bool init = 0;
    while(xR - xL > 1e-7){
        ld md1 = (xL*2 +  xR)/ 3;
        ld md2 = (xL + xR *2 ) / 3;

        init = 0;
        ld y1, y2;
        for(auto f : pos){
            ld y = getY(f, md1);
            if (!init) {
                y1 = y;
                init = 1;
            }
            else{
                y1 = max(y1, y);
            }
        }
        init = 0;
        for(auto f: neg){
            ld y = getY(f, md1);
            if (!init) {
                y2 = y;
                init = 1;
            }
            else{
                y2 = min(y2, y);
            }
        }

        ld val1 = y2 - y1;
        ld y11 = (y1 + y2) / 2;

        init = 0;
        for(auto f : pos){
            ld y = getY(f, md2);
            if (!init) {
                y1 = y;
                init = 1;
            }
            else{
                y1 = max(y1, y);
            }
        }
        init = 0;
        for(auto f: neg){
            ld y = getY(f, md2);
            if (!init) {
                y2 = y;
                init = 1;
            }
            else{
                y2 = min(y2, y);
            }
        }

        ld val2 = y2 - y1;
        ld y22 = (y2 + y1) / 2;

        if (val1 >= val2){
            if (val1 >= 0){
                cout << md1 << ' '<< y11 << '\n';
                return;
            }
            xR = md2;
        }
        else{
            if (val2 >= 0){
                cout << md2 << ' '<< y22 << '\n';
                return;
            }
            xL = md1;
        }
    }


    ld x = (xL + xR)/ 2;
    init = 0;
    ld y1, y2;
    for(auto f : pos){
        ld y = getY(f, x);
        if (!init) {
            y1 = y;
            init = 1;
        }
        else{
            y1 = max(y1, y);
        }
    }
    init = 0;
    for(auto f: neg){
        ld y = getY(f, x);
        if (!init) {
            y2 = y;
            init = 1;
        }
        else{
            y2 = min(y2, y);
        }
    }

    cout << x << ' '<< (y1+y2) /2 << '\n';


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

