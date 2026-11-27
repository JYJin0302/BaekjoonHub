#include <iostream>
#include <vector>
#include <algorithm>
#define vin vector<int>
#define vll vector<ll>
#define arep(i, n) for(auto& (i) : (n))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
using ll = long long;
using namespace std;



int main() {
	int n, k, inp, ans = 0;
	cin >> n >> k;
	vin base(n);
	arep(i, base) cin >> i;

	for (int i = n - 1; i >= 0; i--) {
		ans += k / base[i];
		k %= base[i];
	}
	cout << ans;
}