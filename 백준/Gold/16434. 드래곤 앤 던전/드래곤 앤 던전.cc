#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> room(n);
	for (auto& i : room) {
		int a, b, c;
		cin >> a >> b >> c;
		i = { a, b, c };
	}

	ll dmg = m, hp = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		ll t, a, h;
		tie(t, a, h) = room[i];

		if(t == 2){
			dmg += a;
			hp = min(0ll, hp + h);
		}
		else {

			// 전투
			ll turn = (h + dmg - 1) / dmg;
			hp -= (turn - 1) * a;
		}

        ans = min(ans, hp);
	}

	cout << -ans + 1;
}