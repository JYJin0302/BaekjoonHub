#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dp[1001][1001];  // dp[i][j]:  STR i, INT j 을 만족할 때의 최대 잉여 스탯
int val[1001][1001]; // STR i, INT j 짜리 퀘스트 보상
int cnt[1001][1001];

int ssum(int lx, int ly, int rx, int ry){
    return val[rx][ry] - val[lx-1][ry] - val[rx][ly-1] + val[lx-1][ly-1];
}
int scnt(int lx, int ly, int rx, int ry){
    return cnt[rx][ry] - cnt[lx-1][ry] - cnt[rx][ly-1] + cnt[lx-1][ly-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	int n, STR, INT, PNT;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> STR >> INT >> PNT;
	    val[STR][INT] += PNT;
	    cnt[STR][INT]++;
	}

    for(int i = 1; i <= 1000; i++){
        for (int j = 1; j <= 1000; j++){
            val[i][j] += val[i-1][j] + val[i][j-1] - val[i-1][j-1];
            cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
        }
    }
    for (int i = 1; i <= 1000; i++){
        dp[i][0] = -INF;
        dp[0][i] = -INF;
    }
    
    dp[1][1] = val[1][1] + ssum(2, 1, 1000, 1) + ssum(1, 2, 1, 1000);
    for(int i = 1; i <= 1000; i++){
        for (int j = 1; j <= 1000; j++){
            if (i == 1 && j == 1) continue;
            dp[i][j] = -INF;
            if (dp[i-1][j] > 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + ssum(i, j+1, i, 1000) - 1);
            if (dp[i][j-1] > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + ssum(i+1, j, 1000, j) - 1);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        for (int j = 1; j <= 1000; j++){
            if (dp[i][j] >= 0){
                ans = max(ans, scnt(1, 1, i, 1000) + scnt(1, 1, 1000, j) - scnt(1, 1, i, j));
            }
        }
    }
    cout << ans;
}