#include <bits/stdc++.h>
using namespace std;

string ssum(string s1, string s2) {

	int i1 = s1.size() - 1, i2 = s2.size() - 1;

	string ans = "";

	bool ex = 0;
	while (i1 >= 0 && i2 >= 0) {
		int n1, n2;
		if (s1[i1] >= 'A') n1 = s1[i1] - 'A' + 10;
		else n1 = s1[i1] - '0';
		if (s2[i2] >= 'A') n2 = s2[i2] - 'A' + 10;
		else n2 = s2[i2] - '0';

		int nn = n1 + n2 + ex;
		ex = 0;

		if (nn >= 36) ex = 1;
		nn %= 36;

		if (nn >= 10) ans += 'A' + (nn - 10);
		else ans += '0' + nn;

		i1--;
		i2--;
	}

	if (i2 >= 0) {
		swap(s1, s2);
		swap(i1, i2);
	}

	while (i1 >= 0) {
		int n1;
		if (s1[i1] >= 'A') n1 = s1[i1] - 'A' + 10;
		else n1 = s1[i1] - '0';

		int nn = n1 + ex;
		ex = 0;

		if (nn >= 36) ex = 1;
		nn %= 36;

		if (nn >= 10) ans += 'A' + (nn - 10);
		else ans += '0' + nn;

		i1--;
	}
	if (ex) ans += '1';

	reverse(ans.begin(), ans.end());
	return ans;
}

bool comp(string s1, string s2) {

	if (s1.size() < s2.size()) return 1;
	if (s1.size() > s2.size()) return 0;

	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] < s2[i]) return 1;
		if (s1[i] > s2[i]) return 0;
	}
	return 0;
}

string diff(string s) {
	string ret = "";
	for (char i : s) {
		int n;
		if (i >= 'A') {
			n = 'Z' - i;
		}
		else {
			n = 26 + '9' - i;
		}

		if (n >= 10) {
			ret += 'A' + n - 10;
		}
		else {
			ret += '0' + n;
		}
	}

	return ret;
}

int main() {

	int n;
	cin >> n;
	string ans;

	vector<string> num(36);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ans = ssum(ans, s);
		for (int j = 0; j < s.size(); j++) {
			char k = s[s.size() -1 -j];
			string blank(j, '0');
			blank = '1' + blank;

			if (k >= 'A') {
				num[k - 'A' + 10] = ssum(num[k - 'A' + 10], blank);
			}
			else {
				num[k - '0'] = ssum(num[k - '0'], blank);
			}
		}
	}

	int k;
	cin >> k;

	vector<string> A;
	for (int i = 0; i < 35; i++) {
		int cnt = 34 - i;
		string temp = num[i];
		while (cnt--) {
			temp = ssum(temp, num[i]);
		}
		A.push_back(temp);
	}


	sort(A.begin(), A.end(), comp);

	for (int i = 0; i < k; i++) {
		ans = ssum(ans, A[34 - i]);
	}
	cout << ans;
}