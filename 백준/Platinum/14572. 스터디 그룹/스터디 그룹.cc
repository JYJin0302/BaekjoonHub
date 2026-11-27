#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<pair<int, int>> A;
vector<vector<int>> algo;

int cnt[31];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, d;
    cin >> n >> k >> d;
    
    algo = vector<vector<int>>(n);
    
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        A.push_back({b, i});
        while(a--){
            int c;
            cin >> c;
            algo[i].push_back(c);
        }
    }
    
    sort(A.begin(), A.end());
    
    int r = 0, v = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(r < n && A[r].x - A[i].x <= d) {
            for (int j : algo[A[r].y]) cnt[j]++;
            r++;
        }
        
        int p = r - i;
        int c1 = 0, c2 = 0;
        for (int j = 1; j <= 30; j++) {
            c1 += (cnt[j] == p);
            c2 += (cnt[j] > 0);
        }
        ans = max(ans, p * (c2 - c1));
        
        for (int j : algo[A[i].y]) cnt[j]--;
    }
    cout << ans;
}