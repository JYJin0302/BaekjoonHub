#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N;
	cin >> N;
	
	
	vector<ll> pos(N), cycle(N);

	for (int i = 0; i < N; i++) {
		cin >> pos[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (cycle[i] != 0) continue;
		
		cnt++;
		vector<int> tt;
		
		ll t = i;
		while (cycle[t] == 0) {
			cycle[t] = -1;
			tt.push_back(t);
			t = pos[t];
		}
	}

	if (cnt == 1) cout << 0;
	else cout << cnt;

}