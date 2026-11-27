#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<string> T = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int getV(string s1, string s2) {
	int ix = 0;
	while(T[ix] != s1) ix++;

	int res = ix * 24 * 60;
	res += 60 * stoi(s2.substr(0, 2));
	res += stoi(s2.substr(3, 2));
	return res;
}

void solve() {
	
	

	string s1, s2;
	cin >> s1 >> s2;

	int val1 = getV(s1, s2);
	cin >> s1 >> s2;

	int val2 = getV(s1, s2);

	int res = val2 - val1;
	if (res <= 0) { res += 7 * 24 * 60; }

	int D = res / (24 * 60); res %= 24 * 60;
	int H = res / 60; res %= 60;
	int M = res;
	//cout << D<< ' ' << H << ' ' << M << '\n';

	int zCnt = 0;
	for(auto f : {D, H, M}) if (f == 0) zCnt++;

	if (zCnt == 0){
		cout << D << " " << (D >= 2 ? "days" : "day") << ", ";
		cout << H << " " << (H >= 2 ? "hours" : "hour") << ", ";
		cout << M << " " << (M >= 2 ? "minutes" : "minute") << "\n";
	} else if (zCnt == 1) {
		bool p = 0;
		if(D) {
			cout << D << " " << (D >= 2 ? "days" : "day");
			if(!p) cout << " and ";
			p = 1;
		}
		if (H) {
			cout << H << " " << (H >= 2 ? "hours" : "hour");
			if (!p) cout << " and ";
		}
		if (M) cout << M << " " << (M >= 2 ? "minutes" : "minute");
		cout << '\n';

	} else {
		if(D) cout << D << " " << (D >= 2 ? "days" : "day");
		if(H) cout << H << " " << (H >= 2 ? "hours" : "hour");
		if(M) cout << M << " " << (M >= 2 ? "minutes" : "minute");
		cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}