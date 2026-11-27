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

	if (s == string(n, '1')){
		s.back() = '0';
		cout << s << '\n';
		return;
	}

	int ix = 0;
	while(ix < n && s[ix] == '0') ix++;

	int nx = ix;
	while(nx < n && s[nx] == '1') nx++;
	int len = n - nx;

	int ansi = nx;
	int sx = nx;
	while(nx < n && s[nx] == '0'){
		nx++;
		ansi--;
	}
	ansi = max(ansi, ix);

	string ansS = s;
	for(int i =0; i < len ;i++){
		ansS[sx] = (s[sx] - '0') ^ (s[ansi] - '0') + '0';
		sx++,ansi++;
	}

	// remove leading 0
	reverse(all(ansS));
	while(ansS.size() > 1 && ansS.back() == '0') ansS.pop_back();
	reverse(all(ansS));

	cout << ansS << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
 	cin >> t;
	while (t--) { solve(); }
}