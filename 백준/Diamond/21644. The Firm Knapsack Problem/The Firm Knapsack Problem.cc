#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool cmp(array<ll, 3>& a1, array<ll, 3>& a2){
    return a1[0] * a2[1] < a1[1] * a2[0];
}

void solve(){
    
    int n;
    cin >> n;
    ll W;
    cin >> W;

    ll W2 = W * 3 / 2;

    vector<array<ll, 3>> A;
    for(int i = 0; i < n;i++){
        ll a, b;
        cin >> a>> b;
        if (a <= W2) A.push_back({a, b, i});
    }
    sort(all(A), cmp);

    vector<pair<ll, ll>> rec;
    rec.push_back(mp(0, 0));

    ll curW = 0;
    ll curVal = 0;
    ll mx = 0;
    int ansi = -1;
    int tn = (int)A.size();

    vector<int> tLst;
    for(int i = 0 ; i < tn; i++){
        if (A[i][0] > W/2) {
            tLst.push_back(i);
            continue;
        }

        if (curW + A[i][0] <= W2){
            curW += A[i][0];
            curVal += A[i][1];
            rec.push_back(mp(curW, curVal));
        }
    }

    mx = curVal;
    ansi = -1;
    for(auto f : tLst){
        // test
        int iter = 0;
        int l = 0, r = (int)rec.size() - 1;
        while(l <= r){
            int md = (l+r)>>1;
            if (rec[md].x + A[f][0] <= W2){
                iter = md;
                l = md + 1;
            }
            else r = md - 1;
        }
        ll tans = A[f][1] + rec[iter].y;

        mx = max(mx, tans);
        if (mx == tans){
            ansi = f;
        }
    }

    vector<int> ans;
    curW = 0;
    if (ansi != -1) {
        ans.push_back(ansi);
        curW += A[ansi][0];
    }

    for(int i = 0; i < tn; i++){
        if(i == ansi || A[i][0] > W / 2) continue;
        if (curW + A[i][0] <= W2){
            curW += A[i][0];
            ans.push_back(i);
        }
    }

    cout << (int)ans.size() << '\n';
    for (auto f: ans) cout << A[f][2] + 1 << ' ';
    cout << '\n';
    
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
