#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


bool isPal(string s){
    
    int n = s.size();
    for (int i = 0; i < n/2; i++){
        if (s[i] != s[n-1 - i]) return 0;
    }
    return 1;
}

void solve() {

    int n;
    cin >> n;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    bool ok = 1;
    for (string s : A){
        if (!isPal(s)) ok = 0;
    }
    
    for (int i = 1; i < n; i++){
        if (A[i][0] != A[0][0]) ok = 0;
    }
    
    if (ok) cout << 1;
    else cout << 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	//cin >> T;

	while (T--) {
		solve();
	}
}