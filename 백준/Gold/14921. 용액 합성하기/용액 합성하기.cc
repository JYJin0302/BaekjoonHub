#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i: A )cin >> i;
    
    int temp, ans = INF;
    int l = 0, r = n-1;
    
    while(l < r){
        temp = A[l] + A[r];
        if (abs(ans) > abs(temp)) ans = temp;
        
        if (temp < 0) l++;
        else r--;
    }
    
    cout << ans;
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