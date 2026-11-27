#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


ll w, h;
ll chk(ll a, ll b){
    bool ok = 0;
    if (a == 0 || a == w) ok = 1;
    if (b == 0 || b == h) ok = 1;
    
    if (!ok) return -1;

    ll res = 0;
    if (a == 0) return res + b;
    res += h;
    if (b == h) return res + a;
    res += w;
    if (a == w) return res + h - b;
    res += h;
    return res + w - a;
}

void solve(){   
    
    cin >> w >> h;

    vector<pair<ll, ll>> A;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll v1 = chk(x1, y1);
        ll v2 = chk(x2, y2);

        if(v1 > v2) swap(v1, v2);
        if (v1 == -1) continue;

        A.push_back(mp(v1, v2));
    }
    sort(all(A));


    stack<ll> stk;
    stk.push(w * 5 + h * 5);
    for(auto[a,b] : A){
        while(!stk.empty() && stk.top() < a) stk.pop();
        if (b < stk.top()) stk.push(b);
        else{
            cout << "N\n";
            return;
        }
    }
    cout << "Y\n";

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}