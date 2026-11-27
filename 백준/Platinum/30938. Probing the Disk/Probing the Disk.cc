#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
typedef long long ll;

#define mp make_pair

void solve(){

    ll xpos = -1, ypos = -1, r = 0;

    // getXpos

    ld L = 0, R = 0;
    int cur = 0;
    while(cur < 100000){
        cur += 199;
        cout << "query " << cur << ' ' << 0 << ' ' << cur << ' ' << 100000 << endl;
        cin >> L;

        if (L > 0) break;
    }
    cout <<"query " << cur+1<< ' ' << 0 << ' ' << cur+1 << ' ' << 100000 << endl;
    cin >> R;

    L /= 2;
    R /= 2;

    if(L < R){
        ll tr = R*R - L*L - 1;
        tr /= 2;
        xpos = cur + 1 + tr;
    }
    else{
        ll tr = L*L - R*R - 1;
        tr /= 2;
        xpos = cur - tr;
    }

    pair<ld, ll> mxVal = {-1, -1};
    for(ll i = xpos - 1; i <= xpos + 1; i++){
        cout << "query " << i<< ' ' << 0 << ' '<< i << ' ' << 100000 << endl;
        ld v;
        cin >> v;
        mxVal = max(mxVal, mp(v, i));
    }

    xpos = mxVal.second;
    r = mxVal.first/2 + 0.5;

    // get ypos
    L = 0, R = 0;
    cur = 0;
    while(cur < 100000){
        cur += 199;
        cout << "query " << 0 << ' ' << cur << ' ' << 100000 << ' ' << cur << endl;
        cin >> L;

        if (L > 0) break;
    }
    cout << "query " << 0 << ' ' << cur+1 << ' ' << 100000 << ' ' << cur+1 << endl;
    cin >> R;

    L /= 2;
    R /= 2;

    if(L < R){
        ll tr = R*R - L*L - 1;
        tr /= 2;
        ypos = cur + 1 + tr;
    }
    else{
        ll tr = L*L - R*R - 1;
        tr /= 2;
        ypos = cur - tr;
    }

    mxVal = {-1, -1};
    for(ll i = ypos - 1; i <= ypos + 1; i++){
        cout << "query " << 0 << ' ' << i << ' '<< 100000 << ' ' << i << endl;
        ld v;
        cin >> v;
        mxVal = max(mxVal, mp(v, i));
    }
    ypos = mxVal.second;

    cout << "answer "<< xpos << ' ' << ypos << ' ' << r << endl;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
