#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

ll ansMax[101010];
ll ansMin[101010];

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(a) (int)(a).size()

typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;

void fft(vector<C>& a){
    int n = (int)a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2){
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2*k) rt[i] = R[i] = i&1 ? R[i/2]*x : R[i/2];
    }

    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i/2] | (i&1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for(int k = 1; k < n; k *= 2){
        for(int i = 0; i < n; i+= 2*k) rep(j, 0, k){
            auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
            a[i+j+k] = a[i+j] - z;
            a[i + j] += z;
        }
    }
}

vd conv(const vd& a, const vd& b){
    if (a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i, 0, sz(b)) in[i].imag(b[i]);
    fft(in);
    for(C& x : in) x *= x;
    rep(i, 0, n) out[i] = in[-i & (n-1)] - conj(in[i]);
    fft(out);
    rep(i, 0, sz(res)) res[i] = imag(out[i]) / (4*n);
    return res;
}

void solve(){   
    
    int n;cin >> n;

    vector<ll> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;

    deque<ll> qA, qB;
    ll val = 0;
    int cnt = 0;

    // max
    sort(all(A));
    sort(all(B));
    for(auto f : A) qA.push_back(f);
    for(auto f : B) qB.push_back(f);

    while(cnt < n){
        ll v1 = qA.front() * qB.front();
        ll v2 = qA.back() * qB.back();

        ll res = max(v1, v2);
        if (res < 0) break;

        val += max(v1, v2);
        ansMax[++cnt] = val;
        if (v1 >= v2){
            qA.pop_front();
            qB.pop_front();
        }
        else{
            qA.pop_back();
            qB.pop_back();
        }
    }

    if (cnt < n){
        vd tA, tB;
        while(!qA.empty()) {
            tA.push_back(abs(qA.front()));
            qA.pop_front();
        }
        
        while(!qB.empty()) {
            tB.push_back(abs(qB.front()));
            qB.pop_front();
        }
        sort(all(tA));
        sort(all(tB));

        vd res = conv(tA, tB);
        int ix = 0;
        while(cnt < n){
            ll rr = (ll)(res[ix] + 0.5);
            ansMax[++cnt] = val - rr;
            ix++;
        }
    }
    

    swap(ansMax, ansMin);
    for(auto& i : A) i *= -1;

    val = 0, cnt = 0;
    sort(all(A));
    sort(all(B));
    for(auto f : A) qA.push_back(f);
    for(auto f : B) qB.push_back(f);

    while(cnt < n){
        ll v1 = qA.front() * qB.front();
        ll v2 = qA.back() * qB.back();

        ll res = max(v1, v2);
        if (res < 0) break;

        val += max(v1, v2);
        ansMax[++cnt] = val;
        if (v1 >= v2){
            qA.pop_front();
            qB.pop_front();
        }
        else{
            qA.pop_back();
            qB.pop_back();
        }
    }

    if (cnt < n){
        vd tA, tB;
        while(!qA.empty()) {
            tA.push_back(abs(qA.front()));
            qA.pop_front();
        }
        
        while(!qB.empty()) {
            tB.push_back(abs(qB.front()));
            qB.pop_front();
        }
        sort(all(tA));
        sort(all(tB));

        vd res = conv(tA, tB);
        int ix = 0;
        while(cnt < n){
            ll rr = (ll)(res[ix] + 0.5);
            ansMax[++cnt] = val - rr;
            ix++;
        }
    }
    swap(ansMax, ansMin);

    for(int i = 1; i <= n; i++) cout << -ansMin[i] << ' ' << ansMax[i] << '\n';    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}