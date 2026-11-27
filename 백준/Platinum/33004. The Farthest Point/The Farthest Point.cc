#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<int,int> pi;
using ld = long double;

int A[3];

ld mx = 0;

ld dist2(ld x, ld y){
    return x*x + y*y;
}

ld getVal(ld a, ld b){
    ld res = 10010100;
    res = min(res, dist2(A[0] - b, A[1] + a));
    res = min(res, dist2(A[0] + a, A[1] + b));
    res = min(res, dist2(a, A[1] + A[0] - b));
    res = min(res, dist2(A[0] + A[2] - b, A[1] + A[2] - a));

    res = min(res, dist2(a, A[0] + A[1] + b));
    res = min(res, dist2(A[2] + b, A[0] + A[1] + A[2] - a));
    res = min(res, dist2(b, A[0] + A[1] + a));
    res = min(res, dist2(A[0] + a, A[0] + A[1] + A[2] - b));
    return res;
}

const ld eps = 1e-10;
void goCal(){

    ld la = 0, ra = A[2];
    
    ld res = 0;

    while(la + eps < ra){
        ld ma1 = (2 * la + ra) / 3;
        ld ma2 = (la + 2 * ra) / 3;

        ld resM1 = 0;
        ld lb = 0, rb = A[0];
        while(lb + eps < rb){
            ld mb1 = (2*lb + rb) / 3;
            ld mb2 = (lb + 2*rb) / 3;

            ld v1 = getVal(ma1, mb1);
            ld v2 = getVal(ma1, mb2);

            if(v1 <= v2) {
                resM1 = max(resM1, v2);
                lb = mb1;
            }
            else{
                resM1 = max(resM1, v1);
                rb = mb2;
            }
        }


        ld resM2 = 0;
        lb = 0, rb = A[0];
        while(lb + eps < rb){
            ld mb1 = (2*lb + rb) / 3;
            ld mb2 = (lb + 2*rb) / 3;

            ld v1 = getVal(ma2, mb1);
            ld v2 = getVal(ma2, mb2);

            if(v1 <= v2) {
                resM2 = max(resM2, v2);
                lb = mb1;
            }
            else{
                resM2 = max(resM2, v1);
                rb = mb2;
            }
        }

        if (resM1 >= resM2){
            res = max(res, resM1);
            ra = ma2;
        }
        else{
            res = max(res, resM2);
            la = ma1;
        }
    }

    mx = max(mx, res);
}

void solve(){
    
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A+3);
    mx = (A[0] + A[1])*(A[0] + A[1]) + A[2] * A[2];

    do{
        goCal();
    }while(next_permutation(A, A+3));

    cout << fixed << setprecision(13);
    cout << sqrtl(mx) << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}