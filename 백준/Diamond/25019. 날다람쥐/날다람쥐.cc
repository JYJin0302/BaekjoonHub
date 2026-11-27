#include "squirrel.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e10;
struct T {
	ll x, y, a;
	// 좌표, 기울기
};
long long fly(std::vector<int> tD, std::vector<int> tH, std::vector<int> tW, int tL, int tR) {
	vector<ll> D, H, W;
	for (auto i : tD) D.push_back(i);
	for (auto i : tH) H.push_back(i);
	for (auto i : tW) W.push_back(i);
	ll L = tL, R = tR;
	int n = D.size();

	// 도달 여부 확인
	bool ok = 1;
	for (int i = 0; i < n; i++) {
		if (H[i] < D[i + 1] - D[i]) ok = 0;
	}\
		if (!ok) return -1;

	deque<T> dq;
	dq.push_back({ 0, 0, 0 });
	dq.push_back({ L, 0, W[0] });
	dq.push_back({ H[0], (H[0] - L) * W[0], INF });
	ll pos0 = 0;

	for (int i = 1; i < n; i++) {

		ll dist = D[i] - D[i - 1];
		// 평행이동
		pos0 += dist;
		while (!dq.empty()) {
			T tmp = dq.front();
			dq.pop_front();
			T tmp2 = dq.front();
			if (tmp2.x < pos0) {
				continue;
			}
			if (tmp2.x == pos0) break;

			ll ny = tmp.y + (pos0 - tmp.x) * tmp.a;
			dq.push_front({ pos0, ny, tmp.a });
			break;
		}

		ll na = W[i];
		ll pv = 0, ph = 0;
		while (!dq.empty()) {

			T tmp = dq.back();

			if (tmp.x - pos0 > H[i] || tmp.a > na) {
				dq.pop_back();
				pv = tmp.x;
				ph = tmp.y;
				continue;
			}
			else break;
		}
		if (pv < H[i] + pos0) {
			dq.push_back({ pv, ph, na });
		}
		dq.push_back({ H[i] + pos0, dq.back().y + (H[i] + pos0 - dq.back().x) * dq.back().a, INF });

	}

	ll res = 0;
	while (!dq.empty()) {
		T tmp = dq.back();
		dq.pop_back();

		if (tmp.x > pos0 + R) continue;
		res = tmp.y + (pos0 + R - tmp.x) * tmp.a;
		return res;
	}
    return -1;
}

