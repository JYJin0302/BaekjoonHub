#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
// is 0 palindrome?

ll p10[20];

ll valx = 0, valy = 0;

ll solve(ll num, int x1, int x2, int y1, int y2){

    // current : to make = num
    //           987654321
    // num1 = 000001111100
    //             1   2
    // num2 = 000000001110
    //                1 2

    if (num < 0) return 0;

    if (y2 < x2 && y1 >= y2){
        // unique
        int ny = num / p10[y2-1] % 10;
        ll tval = 0;
        if (y1 != y2) tval = ny*(p10[y2-1] + p10[y1-1]);
        else tval = ny * p10[y2-1];

        ll newN = num - tval;

        if (newN < 0) return 0;
        if (y2 == 1 && y1 != 1 && ny == 0) return 0;

        valy += tval;
        ll tmp = solve(newN, x1, x2, y1-1, y2+1);
        valy -= tval;
        return tmp;
    }

    if (x1 < x2){
        if (num == 0) {
           // cout << "ans found:"<< valx << ' ' << valy << '\n';
           if (valx != 0 && valy!= 0) return 2;
           return 0;
        }
        return 0;
    }

    int ln = to_string(num).size();
    if (ln > x1){
        // unique

        int nx = 9;
        ll tval = 0;
        if (x1 != x2) tval = nx*(p10[x2-1] + p10[x1-1]);
        else tval = nx * p10[x2-1];

        ll newN = num - tval;
        valx += tval;
        ll tmp = solve(newN, x1-1, x2+1, y1, y2);
        valx -= tval;
        return tmp;
    }

    if (ln < x1){
        // unique
        int nx = 0;
        return solve(num, x1-1, x2+1, y1, y2);
    }

    // ln == x1

    int tn = to_string(num)[0] - '0';

    ll res = 0;
    // try tn
    int nx = tn;
    ll tval = 0;
    if (x1 != x2) tval = nx*(p10[x2-1] + p10[x1-1]);
    else tval = nx * p10[x2-1];

    ll newN = num - tval;
    valx += tval;
    res += solve(newN, x1-1, x2+1, y1, y2);
    valx -= tval;

    // try tn-1
    if (tn >= 2 || x2 != 1){
        int nx = tn-1;
        ll tval = 0;
        if (x1 != x2) tval = nx*(p10[x2-1] + p10[x1-1]);
        else tval = nx * p10[x2-1];

        ll newN = num - tval;
        valx += tval;
        res += solve(newN, x1-1, x2+1, y1, y2);
        valx -= tval;
    }

    return res;
}

ll solve2(ll num, int x1, int x2){

    // current : to make = num
    // num1 = 000001111100
    //             1   2
    // num2 = 000001111100
    //             1   2

    if (num < 0) return 0;

    //cout <<"Solve2:"<< num << ' ' << x1 << ' ' << x2 <<'\n';
    if (x1 < x2){
        if (num == 0){
//cout <<"Ans found:\n";
            return 1;
        }
        return 0;
    }

    int tn = num / p10[x2-1] % 10;

    ll res = 0;
    // try 10 + tn
    ll tval = 0;
    if (x2!= x1) tval = (tn+10)*(p10[x2-1] + p10[x1-1]);
    else tval = (tn+10)*p10[x2-1];


    if (tn & 1){
        ll mul = 9 - tn;
        res += mul * solve2(num-tval, x1-1, x2+1);
    }
    else{
        ll mul = 9-tn;
        res += mul * solve2(num-tval, x1-1, x2+1);
    }
    // try tn
    tval = 0;
    if (x2!= x1) tval = tn*(p10[x2-1] + p10[x1-1]);
    else tval = tn*p10[x2-1];


    ll mul = tn+1;
    if (x2 == 1) {
        mul -= 2;
        if (tn == 0) mul = 0;
    }
    res += mul * solve2(num-tval, x1-1, x2+1);

    return res;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    p10[0] = 1;
    for(int i =1 ; i <= 18; i++){
        p10[i] = p10[i-1] * 10;
    }
    // cout <<18 * 18 * (1 << 9);  ~= 160000

    ll n;
    cin >>n;

    int sn = to_string(n).size();

    ll ans = 0;
    for(int i = sn-1; i <= sn; i++){
        for(int j = 1; j <= i; j++){
            if (i != j) ans += solve(n, i, 1, j, 1);
            else ans += solve2(n, i, 1);
        }
    }

    cout << ans;
}
