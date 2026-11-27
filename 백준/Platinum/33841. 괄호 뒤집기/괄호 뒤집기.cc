#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> rec(n*2 + 10);
	int c = 0;
	
	int neg1 = n*2 + 1, neg2 = -1;
	for(int i = 0; i < n*2;i++){
		c += (s[i] == '(' ? 1 : -1);
		rec[i] = c;
		
		if (c < 0){
			neg1 = min(neg1, i);
			neg2 = max(neg2, i);
		}
	}

	if (neg1 == 2*n+1){
		cout << 0 << '\n';
		return;
	}

	int mL = 0, mLi = -1;
	for(int i = 0; i < neg1; i++){
		if (rec[i] >= mL) {
			mL= rec[i];
			mLi = i;
		}
	}

	int mR = 0, mRi = n*2 - 1;
	for(int i = neg2; i < n*2; i++){
		if (rec[i] > mR){
			mR = rec[i];
			mRi = i;
		}
	}

	bool ok = 1;
	for(int i = mLi + 1; i < mRi; i++){
		if (rec[i] > mL + mR){
			ok = 0;
		}
	}

	if (ok){
		cout << 1 << '\n';
		cout << mLi + 2 << ' ' << mRi + 1 << '\n';
		return;
	}

	int mx = 0, mdx = 0;
	for(int i =0 ; i < n*2; i++){
		if (rec[i] > mx) {
			mx = rec[i];
			mdx = i;
		}
	}

	cout << 2 << '\n';
	cout << 1 << ' ' << mdx + 1 << '\n';
	cout << mdx + 2 << ' '<< n*2 << '\n';

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int t = 1;
 	cin >> t;
	while (t--) { solve(); }
}