#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
int n = sz(a), L = 31- __builtin_clz(n);
static vector<complex<long double>> R(2, 1);
static vector<C> rt(2, 1); // (^ 10% faster if double)
for (static int k = 2; k < n; k *= 2) {
R.resize(n); rt.resize(n);
auto x = polar(1.0L, acos(-1.0L) / k);
rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
}
vi rev(n);
rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
for (int k = 1; k < n; k *= 2)
for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled) /// include-line
auto x = (double *)&rt[j+k], y = (double
*)&a[i+j+k];
/// exclude-line
C z(x[0]*y[0]- x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
/// exclude-line
a[i + j + k] = a[i + j]- z;
a[i + j] += z;
}
}
vd conv(const vd& a, const vd& b) {
if (a.empty() || b.empty()) return {};
vd res(sz(a) + sz(b)- 1);
int L = 32- __builtin_clz(sz(res)), n = 1 << L;
vector<C> in(n), out(n);
copy(all(a), begin(in));
rep(i,0,sz(b)) in[i].imag(b[i]);
fft(in);
for (C& x : in) x *= x;
rep(i,0,n) out[i] = in[-i & (n- 1)]- conj(in[i]);
fft(out);
rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
return res;
}

int P[1001010];

void solve(){
        
    vd tmp(1000001), tmp2(1000001), tmp3(1000001);

    for(int i = 2; i <= 1000000; i++){
        if (P[i]) continue;
        for(int j = i*2; j <= 1000000; j += i){
            P[j] = 1;
        }
    }

    tmp[2] = 1;
    tmp2[4] = 1;
    for(int i = 3; i <= 1000000; i += 2){
        if (!P[i]) {
            tmp[i] = 1;
            if (i*2 <= 1000000) tmp2[i*2] = 1;
        }
    }

    vd r1 = conv(tmp, tmp);
    while((int)r1.size() >= 1000001) r1.pop_back();
    for(auto& i : r1){
        i = (ll)(i + 0.5);
    }
    vd res3 = conv(r1, tmp);
    
    vd res2 = conv(tmp2, tmp);



    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;

        ll ans3 = (ll)(res3[x] + 0.5); 
        ll ans2 = (ll)(res2[x] + 0.5);
        ll ans1 = (x % 3 == 0 && !P[x/3]);

        cout << (ans3 - (ans2 - ans1) * 3 - ans1) / 6 + ans2 << '\n';
    }


}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}