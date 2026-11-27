#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
vector<pair<int, int>> A[1 << 10];
 
const int INF = 0x3f3f3f3f;
int dp[1 << 10], tdp[1 << 10];
vector<int> dpIdx[1 << 10], tdpIdx[1 << 10];
void solve() {
 
    int n;
    cin >> n;
 
    // length, bit, idx
 
    for(int i = 0; i < n;i++){
        string s;
        cin >> s;
 
        vector<int> cnt(10);
        for(auto f : s) cnt[f-'0']++;
 
        int b = 0;
        for(int j = 0; j < 10; j++) if (cnt[j] % 2) b += 1 << j;
        A[b].push_back(mp((int)s.size(), i+1));
        sort(all(A[b]));
        if (A[b].size() >= 3) A[b].pop_back();
    }
 
    int ansLen = INF;
    vector<int> ansIdx = {};
 
    // 같은 타입 두 개 사용
    for(int i = 0; i < (1 << 10); i++){
        if(A[i].size() >= 2){
            int tmpLen = A[i][0].x + A[i][1].x;
            if (tmpLen < ansLen){
                ansLen = tmpLen;
                ansIdx = {A[i][0].y, A[i][1].y};
            }
        }
    }
 
    vector<bool> ansBit(1 << 10);
    ansBit[0] = 1;
    for(int i = 0; i < 10; i++){
        ansBit[1 << i] = 1;
    }
 
    memset(dp, INF, sizeof dp);
    dp[0] = 0;
    for(int i = 0; i < (1 << 10); i++){
        if (A[i].empty()) continue;
        
        for(int j = 0; j <(1 << 10); j++){            
            tdp[j] = INF;
            tdpIdx[j].clear();
        }
 
       // cout << "UPD: "<< A[i][0].x << ' '<< A[i][0].y << '\n';
 
        for(int j = 0; j <(1 << 10); j++){            
            if (dp[j] == INF) continue;
            int ti = j ^ i;
            int newLen = dp[j] + A[i][0].x;
 
           // cout << "Go upd: " << ti << ' '<< newLen << '\n';
 
            if (tdp[ti] > newLen){
                tdp[ti] = newLen;
                tdpIdx[ti] = dpIdx[j];
                tdpIdx[ti].push_back(A[i][0].y);
            }
        }
 
        for(int j = 0; j <(1 << 10); j++){   
            if (ansBit[j]){
                if (ansLen > tdp[j]){
                    ansLen = tdp[j];
                    ansIdx = tdpIdx[j];
                }
                continue;
            }         
            if (dp[j] > tdp[j]){
                dp[j] = tdp[j];
                dpIdx[j] = tdpIdx[j];
            }
        }
    }
 
    if (ansLen == INF){
        cout << -1 << '\n';
        return;
    }
    sort(all(ansIdx));
    cout << ansLen << '\n';
    cout << ansIdx.size() << '\n';
    for(auto f : ansIdx) cout << f<< ' ';
    cout << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
