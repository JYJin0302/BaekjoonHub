#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
    
    int mx = -1;
    
    int mv = n;
    
    if (mv <= min(210, n + 8)){
        mx = 1;
        mv = min(210, n+8);
    }
    
    if (mv <= min(220, n+4)){
        mx = 2;
        mv = min(220, n+4);
    }
    
    if (mv <= min(230, n+2)){
        mx = 3;
        mv = min(230, n+2);
    }
    
    if (mv <= min(240, n+1)){
        mx = 4;
        mv = min(240, n+1);
    }

    cout << mx;
}