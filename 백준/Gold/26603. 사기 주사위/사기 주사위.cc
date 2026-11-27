#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> A(n);
	for (auto& i : A) {
		for (int j = 0; j < 4; j++) {
			int x;
			cin >> x;
			i.push_back(x);
		}
	}

	/*
	    0
      1   3
	    2

		4
	  5   7
	    6	
	*/


	vector<int> D = { 0, 1, 2, 3, 4, 5, 6, 7 };
	


	vector<vector<int>> ck = {
		{0, 1, 3, 4},
		{0, 2, 3, 7},
		{1, 2, 3, 6},
		{0, 1, 2, 5},
		{0, 4, 5, 7},
		{1, 4, 5, 6},
		{2, 5, 6, 7},
		{3, 4, 6, 7}
	};

	bool valid = 0;
	do {

		bool ok = 1;

		for (auto i : A) {


			bool f = 0;
			vector<int> tmp;
			for (auto j : i) tmp.push_back(D[j-1]);

			sort(tmp.begin(), tmp.end());

			for (auto k : ck) {
				if (k == tmp) {
					f = 1;
					break;
				}
			}
			
			if (!f) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			valid = 1;
			break;
		}

	} while (next_permutation(D.begin()+1, D.end()));
	
	if (valid) cout << "Hmm...";
	else cout << "You're gonna die!";
}