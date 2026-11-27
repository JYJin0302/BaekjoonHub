#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 2147483647;

ll dp[2021][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> A(n+1);
	for(int i = 0; i < n+1; i++) cin >> A[i];
	
	dp[0][0] = 1; dp[0][1] = 1;
	for(int i = 1; i <= n; i++){
		
		if(A[i] > A[i-1]){
			
			for(int j = i; j <= n; j++){
				if (A[j] > A[i-1]){
					dp[j][0] = (dp[j][0] + dp[i-1][1]) % mod;
				}
				else break;
			}
			
		}
		else{
			
			for(int j =i; j <= n; j++){
				if (A[j] < A[i-1]){
					dp[j][1] = (dp[j][1] + dp[i-1][0]) % mod;
				}
				else break;
			}
			
		}
	}
	
	ll ans = (dp[n][0] + dp[n][1]) % mod;
	cout << ans;
	
}