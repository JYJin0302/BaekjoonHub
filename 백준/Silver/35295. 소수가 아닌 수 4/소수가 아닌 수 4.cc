#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool isP[1001010];

void solve() {
	
	for(int i = 2; i <= 1000000; i++){
		if (isP[i]) continue;
		for(int j = i *2; j <= 1000000; j += i) isP[j] = 1;
	}
	int n;
	cin >> n;
	vector<int> A(n);
	for(auto& i : A) cin >> i;

	for(int i =0;i < n; i++){
		for(int j = i + 1;j  <n; j++){
			int v = A[i] * A[j];
			if(isP[v]){
				cout << "YES\n";
				cout << 2 << '\n' << A[i] << ' ' << A[j] << '\n';
				return;
			}
		}
	}
	cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}