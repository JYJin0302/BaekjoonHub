#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b % a, a);
}

void solve(int n) {

	ll lcm = 1;
	for (int i = 2; i <= n; i++) {
		lcm = lcm * i / gcd(i, lcm);
	}
	//cout << lcm << '\n';

	ll nom = 0;
	for (int i = 1; i <= n; i++) {
		nom += lcm / i;
	}
	nom *= n;


	ll n1 = nom / lcm;
	nom %= lcm;

	ll tm = gcd(nom, lcm);
	nom /= tm, lcm /= tm;

	if (nom == 0) {
		cout << n1 << '\n';
		return;
	}

	int sz1 = to_string(n1).size();
	int sz2 = to_string(lcm).size();
	cout << string(sz1 + 1, ' ') << nom << '\n';
	cout << n1 << ' ' << string(sz2, '-') << '\n';
	cout << string(sz1 + 1, ' ') << lcm << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	while (cin>> x) {
		solve(x);
	}
}