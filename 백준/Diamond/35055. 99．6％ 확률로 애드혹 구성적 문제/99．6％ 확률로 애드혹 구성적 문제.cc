#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int n, q;
array<int, 4> Q[606060], tmp[606060];
int ans[202020];
int maxN = 200012;

int fw[404040];
void update(int ix, int val, bool over = 0){
    while(ix <= maxN){
        if (over) fw[ix] = val;
        else fw[ix] = min(fw[ix], val);
        ix += ix & -ix;
    }
}

int getM(int ix){
    int ret = 202020;
    while(ix){
        ret= min(ret, fw[ix]);
        ix -= ix & -ix;
    }
    return ret;
}


void CDQ(int l, int r){
    if(r == l) return;

    int md = (l+r)>>1;
    CDQ(l, md);
    CDQ(md+1, r);

    // cout << "Now processIng: " << l << ' ' << r << " => ";
    // for(int i = l ; i <= r; i++){
    //     cout << "( ";
    //     for(int j = 0;j < 4; j++) cout << Q[i][j] << ' ';
    //     cout << ") ";
    // }
    // cout << '\n';
    int p1 = l, p2 = md+1;
    int cur = l;
    vector<int> upLst;
    while(p1 <= md && p2 <= r){
        if (array<int, 3>({Q[p1][1], Q[p1][2], Q[p1][3]}) <= array<int, 3>({Q[p2][1], Q[p2][2], Q[p2][3]})){
            tmp[cur++] = Q[p1];
            auto P = Q[p1];
            if (P[3] < 0) {
                // update
                int r = P[2];
                int val = P[1] + P[0] - n - 1;
                //cout << "update: " << r<< ' ' << val << '\n';
                upLst.push_back(r);
                update(r, val);
            }

            p1++;
        }
        else{
            tmp[cur++] = Q[p2];
            auto P = Q[p2];
            if (P[3] > 0) {
                // get Answer
                int k = P[2];
                int ix = P[3];
                int v = getM(k);
                //cout << "Get ans: " << ix << ' ' << k << ' '<< v << '\n';
                ans[ix] = min(ans[ix], v);
            }
            p2++;
        }
    }

    while(p1 <= md){
        tmp[cur++] = Q[p1++];
    }

    while(p2 <= r){
        tmp[cur++] = Q[p2];
        if (Q[p2][3] > 0){
            int k = Q[p2][2];
            int ix = Q[p2][3];
            int v = getM(k);
           // cout << "Get ans: " << ix << ' ' << k << ' '  << v<< '\n';
            ans[ix] = min(ans[ix], v);
        }
        p2++;
    }

    for(auto f : upLst) update(f, 202020, 1);
    for(int i = l; i <= r; i++){
        Q[i] = tmp[i];
    }

    // cout << "Done:                  ";
    // for(int i = l ; i <= r; i++){
    //     cout << "( ";
    //     for(int j = 0;j < 4; j++) cout << Q[i][j] << ' ';
    //     cout << ") ";
    // }
    // cout << '\n' << '\n';
}

void solve(){
    
    cin >> n >> q;
    vector<int> A(n+1);
    for(int i = 1;i <= n; i++) cin >> A[i];

    vector<int> num = {0};
    
    for(int i =0 ; i <q; i++){
        int a, b, k;
        cin >> a>> b >> k;
        Q[i] = {n + 1 - a, b, k, i + 1};
        num.push_back(k);
    }
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    int ns = (int)num.size();
    for(int i = 0; i < q; i++){
        auto& f = Q[i];
        f[2] = lower_bound(all(num), f[2]) - num.begin();
        f[2] = ns + 1 - f[2];
    }

    vector<pair<int, int>> res;
    stack<pair<int, int>> stk;
    for(int i = 1; i <= n; i++){
        int v = A[i];
        while(!stk.empty() && stk.top().x < v) stk.pop();
        if(!stk.empty()){
            res.push_back(mp(stk.top().y, i));
            //cout << "Found: " << stk.top().y << ' ' << i << '\n';
        }
        stk.push(mp(v, i));
    }


    while(!stk.empty()) stk.pop();
    for(int i = n; i >= 1; i--){
        int v = A[i];
        while(!stk.empty() && stk.top().x < v) stk.pop();
        if(!stk.empty()){
            res.push_back(mp(i, stk.top().y));
           // cout << "FOund: " << stk.top().y << ' ' << i << '\n';
        }
        stk.push(mp(v, i));
    }
    sort(all(res));
    res.erase(unique(all(res)), res.end());

    int qS = q;
    for(auto[a,b] : res){
        int v= A[a] + A[b];
        v = lower_bound(all(num), v+1) - num.begin() - 1;

       // cout << a<< ' '<< b << ' ' << A[a] + A[b] << " " << v << '\n';
        if (v) {
            Q[qS++] = {n + 1 - a, b, ns + 1 - v, -1};
        }
    }

    sort(Q, Q + qS);
    // for(int i = 0; i < qS; i++){
    //     cout << "( ";
    //     for(int j = 0;j < 4; j++) cout << Q[i][j] << ' ';
    //     cout << ") ";
    // }
    // cout << '\n';
    
    for(int i= 1; i <= q; i++) ans[i] = n + 100;


    for(int i =1;i <= 404020; i++) fw[i] = n + 100;
    CDQ(0, qS - 1);

    for(int i = 1; i <= q; i++){
        if (ans[i] > n) cout << -1 << '\n';
        else cout << ans[i] << '\n';
    }
    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
