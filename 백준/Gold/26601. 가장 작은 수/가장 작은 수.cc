#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T {
	ll b, ex;
};

struct cmp {

	bool operator()(T& a, T& b) {
		long double v1 = 1.0 * a.ex / b.ex;
		long double v2 = log(b.b) / log(a.b);
		return v1 > v2;
	}

};

const ll mod = 2000003;
ll fastPow(ll b, ll ex, ll m) {
	ll res = 1;
	while (ex) {
		if (ex % 2) res = res * b % m;
		ex /= 2;
		b = b * b % m;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> tp(2000000),p;

	priority_queue<T, vector<T>, cmp> pq;

	for (int i = 2; i < 2000000; i++) {
		if (tp[i] == 0) {
			p.push_back(i);
			pq.push({ i, 1 });
			for (int j = i * 2; j < 2000000; j += i) tp[j] = 1;
		}
	}

	ll ans = 1;
	int cnt = 0;
	while (cnt < n) {

		T tmp = pq.top();
		pq.pop();

		ans = ans * fastPow(tmp.b, tmp.ex, mod) % mod;
		pq.push({ tmp.b, tmp.ex * 2 });
		cnt++;
	}
	cout << ans;

}