#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int chk(char c1, char c2, char c3){
	if (c1 == '+' && c2 == '^' && c3 == '+') return 1;
	if (c1 == '-' && c2 == '^' && c3 == '-') return -1;
	return 0;
}

int n;
int A[303030];
int D[303030];
int seg[606060];

void update(int ix, int val){
	seg[ix += n] = val;
	while(ix > 1){
		seg[ix >> 1] = max(seg[ix], seg[ix ^ 1]);
		ix >>= 1;
	}
}

int getMax(int l, int r){
	int res = 0;
	for(l += n ,r  += n; l < r; l >>= 1, r>>= 1){
		if (l  & 1) res = max(res, seg[l++]);
		if (r & 1) res = max(res, seg[--r]);
	}
	return res;
}

void solve(){

	string s;cin >> s;
	n = s.size();

	s = "..." + s + "...";


	for(int i = 0; i < n; i++){
		int res = chk(s[i + 3 - 2], s[i+3 -1], s[i+3]);
		A[i+1] = res;
		A[i+1] += A[i];
	}


	for(int i = 3; i < n + 3; i++){
		int dd = 0;
		for(int j = 0; j < 3; j++){
			dd -= chk(s[i + j - 2], s[i + j -1 ], s[i + j]);
		}
		dd += chk(s[i - 2], s[i - 1], s[i + 1]);
		dd += chk(s[i - 1], s[i + 1], s[i + 2]);
		D[i-3] = dd;

		update(i-2, dd);
	}

	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;

		if(r - l < 2) {
			cout << 0 << '\n';
			continue;
		}

		if (r - l == 2){
			int val = A[r] - A[l+1];
			cout << max(val, 0) << '\n';
			continue;
		}

		int base = A[r] - A[l+1];

		int bb = getMax(l + 2, r - 1);

		// get cal : l, l+1, r-1, r
		bb = max(bb, -chk(s[l+2], s[l+3], s[l+4])); // l
		bb = max(bb, -chk(s[r+2-2], s[r+2-1], s[r+2])); // r

		int tmp = 0;
		tmp -= chk(s[l+2], s[l+3], s[l+4]);
		tmp -= chk(s[l+3], s[l+4], s[l+5]);
		tmp += chk(s[l+2], s[l+4], s[l+5]);
		bb =max(bb, tmp);

		tmp = 0;
		tmp -= chk(s[r+2-2], s[r+2-1], s[r+2]);
		tmp -= chk(s[r+2-3], s[r+2-2], s[r+2-1]);
		tmp += chk(s[r+2-3], s[r+2-2], s[r+2]);
		bb = max(bb, tmp);

		cout << base + bb << '\n';
	}
	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
