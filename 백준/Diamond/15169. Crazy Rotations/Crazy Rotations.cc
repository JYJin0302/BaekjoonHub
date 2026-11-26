#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(x) begin(x), end(x)
#define x first
#define y second
#define mp make_pair

using real_t = double;
using cpx = complex<real_t>;
void FFT(vector<cpx> &a, bool inv_fft = false) {
	int N = a.size();
	vector<cpx> root(N / 2);
	for (int i = 1, j = 0; i < N; i++) {
		int bit = N / 2;
		while (j >= bit) j -= bit, bit >>= 1;
		if (i < (j += bit)) swap(a[i], a[j]);
	}
	long double ang = 2 * acosl(-1) / N * (inv_fft ? -1 : 1);
	for (int i = 0; i < N / 2; i++) root[i] = cpx(cosl(ang * i), sinl(ang * i));
	/*
	NTT : ang = pow(w, (mod-1)/n) % mod, inv_fft-> ang^{-1},
	root[i] = root[i-1] * ang
	XOR Convolution : set roots[*] = 1, a[j+k] = u+v, a[j+k+i/2] =
	u-v
	OR Convolution : set roots[*] = 1, a[j+k+i/2] += inv_fft ?-u
	: u;
	AND Convolution : set roots[*] = 1, a[j+k ] += inv_fft ?-v :
	v;
	*/
	for (int i = 2; i <= N; i <<= 1) {
		int step = N / i;
		for (int j = 0; j < N; j += i)
			for (int k = 0; k < i / 2; k++) {
				cpx u = a[j + k], v = a[j + k + i / 2] * root[step * k];
				a[j + k] = u + v;
				a[j + k + i / 2] = u - v;
			}
	}
	if (inv_fft)
		for (int i = 0; i < N; i++)
			a[i] /= N;  // skip for
			            // AND / OR convolution.
}
vector<ll> multiply(const vector<ll> &_a, const vector<ll> &_b) {
	vector<cpx> a(all(_a)), b(all(_b));
	int N = 2;
	while (N < a.size() + b.size()) N <<= 1;
	a.resize(N);
	b.resize(N);
	FFT(a);
	FFT(b);
	for (int i = 0; i < N; i++) a[i] *= b[i];
	vector<ll> ret(N);
	FFT(a, 1);  // NTT : just return a
	for (int i = 0; i < N; i++) ret[i] = llround(a[i].real());
	while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
	return ret;
}

int n, p;
int ans[505050];
void getVal(vector<int> &v) {
	vector<ll> v1(2 * n), v2(n);
	for (auto f : v) {
		v1[f] = v1[f + n] = 1;
		v2[n - 1 - f] = 1;
	}

	vector<ll> res = multiply(v1, v2);
	for (int i = 0; i < n; i++) { ans[i] += res[i + n - 1]; }

	// cout << "RES: ";
	// for (int i = 1; i < n; i++) cout << res[i + n - 1] << ' ';
	// cout << '\n';
}

void solve() {
	cin >> n >> p;

	string s;
	cin >> s;

	vector<int> R, B, Y;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') R.push_back(i);
		else if (s[i] == 'B') B.push_back(i);
		else Y.push_back(i);
	}

	getVal(R);
	getVal(B);
	getVal(Y);

	vector<pair<int, int>> res(n - 1);
	for (int i = 1; i < n; i++) {
		ans[i] = n - ans[i];
		res[i - 1] = mp(ans[i], i);
	}
	sort(all(res));

	int ans = p - 1;
	while (ans && res[ans].x == res[ans - 1].x) ans--;

	cout << res[ans].y << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; i++) { solve(); }
	return 0;
}