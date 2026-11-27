#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


const int mod = 1e9 + 7;
pair<int, int> A[505050];
ll sA[505050];
int sA_k[505050];

pair<int, int> seg[1202020];

void init(int l, int r, int n){
    seg[n] = mp(1e9 + 100, -1);
    if (l== r) return;
    int md = (l+r)>>1;
    init(l, md, n*2);
    init(md+1,r, n*2+1);
}

void update(int l, int r, int n, int ix, pair<int, int> val){
    if (l > ix || r < ix) return;
    if (l == ix && r == ix){
        seg[n] = val;
        return;
    }

    int md = (l+r)>>1;
    update(l, md, n*2, ix, val);
    update(md+1,r, n*2+1, ix, val);
    seg[n] = min(seg[n*2],seg[n*2+1]);
}

pair<int, int> getMin(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return mp(1e9 + 100, -1);
    if (l >= sl && r <= sr) return seg[n];
    int md = (l+r)>>1;
    return min(getMin(l, md,n*2, sl, sr), getMin(md+1, r, n*2+1, sl, sr));
}

ll ans = 0;

map<int, int> st[505050];

int n, k;
void goSolve(int l, int r){
    if(l > r) return;
    pair<int, int> md = getMin(0, n-1, 1, l, r);
    if(md.y == -1) {
        for(int i = l; i <=r ;i++){
            st[l][sA_k[i]]++;
        }
        return;
    }
    //cout << "Go solve: " << l << ' ' << r << ' ' << md.x << ' ' << md.y << '\n';

    if (l == r){
        if (A[l].x % k == 0) ans -= md.x;
        ans = (ans + mod) % mod;
        st[l][sA_k[l]]++;
        return;
    }
    int m = md.y;

    goSolve(l, m-1);
    goSolve(m+1, r);
    // cout << "L: ";
    // for(auto[a,b]: st[l]) cout << a << ' ' << b<< " | ";
    // cout << '\n';
    // cout << "M+1: ";
    // for(auto[a,b]: st[m+1]) cout << a << ' ' << b<< " | ";
    // cout << '\n';

    ll cnt = 0;
    if (m - l <= r - m){
        st[m+1][sA_k[m]]++;

        

        for(int j = l; j <= m; j++){
            ll off = (j ? sA_k[j-1] : 0);
           // cout << "Count off: " << off << " | " << st[m+1][off] << '\n';
            cnt += st[m+1][off];
        }

        for(auto [a,b] : st[l]) st[m+1][a] += b;
        swap(st[m+1], st[l]);
    }
    else{
        
        if(l) st[l][sA_k[l-1]]++;
        else st[l][0]++;
        for(int j = m; j <= r; j++){
            ll off = sA_k[j];
            cnt += st[l][off];
        }
        if (l)st[l][sA_k[l-1]]--;
        else st[l][0]--;

        for(auto [a,b]: st[m+1]) st[l][a] += b;
        st[l][sA_k[m]]++;
    }
    cnt %= mod;
    ans = ans + mod - cnt * md.x % mod;
    ans %= mod;
}

void solve(){
    
    cin >> n >> k;

    
    init(0, n-1, 1);
    
    for(int i =0 ;i < n; i++){
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        A[i] = mp(a, b);
        if (a % k != b % k){
            //lst.push_back(mp(a - b, i));
            update(0, n-1, 1, i, mp(a-b, i));
        }
    }

    for(int i =0 ;i < n; i++){
        sA_k[i] = A[i].x + (i ? sA_k[i-1] : 0);
        sA_k[i] %= k;

        sA[i] = A[i].x + (i ? sA[i-1] : 0);
        sA[i] %= mod;
    }

    ll tot = 0;
    ll val = 0;
    for(int i =0; i < n; i++){
        tot += (sA[i] * (i+1)) - val ;
        tot %= mod;
        val += sA[i];
        val %= mod;
    }

    //cout << tot << '\n';
    ans += tot;

   // for(auto[a,b]: A) cout << a<< ' ' << b << '\n';

    goSolve(0, n-1);

    for(int i =0 ; i < n; ){
        if (A[i].x % k != A[i].y % k) {
            i++;
            continue;
        }
        map<int, int> cc;
        map<int, ll> ss;
        if(i) cc[sA_k[i-1]] = 1, ss[sA_k[i-1]] = sA[i-1];
        else cc[0] = 1;

        ll tval = 0;
        int ni = i;
        while(ni < n && A[ni].x % k == A[ni].y% k){
            int v = sA_k[ni] % k;
            tval += sA[ni] * cc[v] - ss[v];
            tval = (tval % mod + mod) % mod;
            cc[v]++;
            ss[v] += sA[ni];
            ss[v] %= mod;
            ni++;
        }

        ans = (ans + mod -  tval) % mod;
        i = ni;

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

