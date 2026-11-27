#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


int gcd(int a, int b){
	if (a == 0) return b;
	return gcd(b%a, a);
}

void solve(){

	int n;
	cin >> n;

	if (n <= 4){
		for(int i = 1; i <= n; i++){
			if (i == 1) cout << 1 << ' ';
			else cout << i-1 << ' ';
		}
		cout << '\n';
		cout << 1  << ' ' << n << '\n';
		return;
	}
	
	if (n == 5){
		cout << "2 3 1 5 4\n";
		cout << 1 << ' ' << 5 << '\n';
		return;
	}
	if (n == 6){
		cout << "2 3 1 5 4 5\n";
		cout << 1 << ' ' << 6 << '\n';
		return;
	}

	int n1 = n/2, n2 = n - n1;
	while(gcd(n1, n2) != 1){
		n1--, n2++;
	}

	for(int i = 1; i <= n1; i++){
		if (i == 1) cout << n1 << ' ';
		else cout << i-1 << ' ';
	}

	for(int i = 1; i <= n2; i++){
		if (i == 1) cout << n << ' ';
		else cout << n1 + i - 1 << ' ';
	}
	cout << '\n';
	cout << 1<< ' ' << n << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}