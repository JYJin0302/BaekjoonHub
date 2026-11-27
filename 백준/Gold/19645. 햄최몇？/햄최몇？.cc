#include <bits/stdc++.h>
using namespace std;

bool dp[2501][2501], tmp[2501][2501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int tot = 0;
    vector<int> A(n);
    for(auto& i : A) {
        cin >> i;
        tot += i;
    }
    
    sort(A.begin(), A.end());
    
    dp[0][0] = 1;
    for(int x : A){
        for(int i = 0; i <= 2500; i++){
            for (int j = i; j <= 2500; j++){
                if (dp[i][j]){
                    tmp[i][j] = 1;
                    if (j + x <= 2500) tmp[i][j+x] = 1;
                    if (i + x <= j) tmp[i+x][j] = 1;
                    else if (i+x <= 2500) tmp[j][i+x] = 1;
                }
            }
        }
        swap(tmp, dp);
    }
    
    int ans = 0;
    for (int i = 0; i <= 2500; i++){
        for (int j = i; j <= 2500; j++){
            if (dp[i][j] && tot - i - j <= i) ans = max(ans, tot - i - j);
        }
    }
    cout << ans;
}