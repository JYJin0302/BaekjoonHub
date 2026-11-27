#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt = 9, tar;
string ans(10, '0');
bool found = 0;
void bt(int l, int li = 0) {

	int b = 10 - l;
	if (li == l) {
		cnt++;
		if (cnt == tar) found = 1;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (li == 0 && i == 0) continue;
		if (li == 0 || ans[b + li - 1] - '0' > i) {
			ans[b + li] = i + '0';
			bt(l, li + 1);
			if (found) return;
			ans[b + li] = '0';
		}
	}
}


int main() {

	cin >> tar;

	if (tar <= 10) {
		cout << tar;
		return 0;
	}

	int len = 2;
	while (!found && len <= 10) {
		bt(len);
		len++;
	}

	ll ret = stoll(ans);
	if (ret == 0) ret = -1;
	cout << ret;
}