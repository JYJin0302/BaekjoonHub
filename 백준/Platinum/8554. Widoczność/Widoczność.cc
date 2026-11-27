#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n;
    cin >> n;
    vector<int>A(n);
    for(auto& i : A) cin >> i;

    vector<int> num = A;
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    for(auto& i : A) {
        i = lower_bound(all(num), i) - num.begin() + 1;
    }

    stack<pair<int, int>> stk;

    ll ans = 0;
    int sCnt = 0;
    vector<int> cntL(n),cntR(n);
    vector<int> cntL2(n), cntR2(n);
    vector<int> cntL3(n), cntR3(n);
    for(int i= 0; i < n; i++){

        while(!stk.empty() && stk.top().x <= A[i]){  
            bool t = 0;
            if(stk.top().x == A[i]) {
                t = 1;
                cntR3[stk.top().y]++;
                sCnt++;
            }
            else cntR2[stk.top().y]++;
            ans++;
            stk.pop();
            if (!t) cntL[i]++;
        }

        stk.push(mp(A[i], i));
    }
    while(!stk.empty()) stk.pop();

    for(int i= n-1; i >= 0; i--){
        while(!stk.empty() && stk.top().x <= A[i]){  
            bool t =0;
            if(stk.top().x == A[i]) {
                t = 1;
                cntL3[stk.top().y]++;
            }
            else cntL2[stk.top().y]++;
            ans++;
            stk.pop();
            if(!t) cntR[i]++;
        }
        stk.push(mp(A[i], i));
    }
    while(!stk.empty()) stk.pop();
    ans -= sCnt;

    // for(auto f : A) cout << f<< ' ';
    // cout << '\n';
    // cout << sCnt << '\n';

    // cout << "small\n";
    // for(auto f: cntL) cout << f<< ' ';
    // cout << '\n';
    
    // for(auto f: cntR) cout << f<< ' ';
    // cout << '\n';

    // cout << "big\n";
    // for(auto f: cntL2) cout << f<< ' ';
    // cout << '\n';
    
    // for(auto f: cntR2) cout << f<< ' ';
    // cout << '\n';

    
    // cout << "eq\n";
    // for(auto f: cntL3) cout << f<< ' ';
    // cout << '\n';
    
    // for(auto f: cntR3) cout << f<< ' ';
    // cout << '\n';

    



    for(int i= 0; i < n; i++){
        ans += 1ll * (cntL[i] + cntL3[i]) * (cntR[i] + cntR3[i]);
        ans += 1ll * cntL2[i] * (cntR[i] + cntR3[i]);
        ans += 1ll * (cntL[i] + cntL3[i]) * cntR2[i];
    }
    cout << ans << '\n';
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
