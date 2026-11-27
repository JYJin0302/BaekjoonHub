#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;
vector<pair<int, int>> R, L;
bool ok;

void foldPaper(){
    
    for (int i = 1; i < n; i++){
        // 홀수: 오른쪽, 짝수: 왼쪽
        int a, b;
        a = A[i-1], b = A[i];
        if (a > b) swap(a, b);
        
        if (i % 2){
            // valid test
            for (auto k : R){
                int x, y;
                tie(x, y) = k;
                
                if (x < a && y > a && y < b) return;
                if (x > a && x < b && y > b) return;
            }
            R.push_back({a, b});
        }
        else{
            for (auto k : L){
                int x, y;
                tie(x, y) = k;
                
                if (x < a && y > a && y < b) return;
                if (x > a && x < b && y > b) return;
            }
            L.push_back({a, b});
        }
    }
    ok = 1;
}

int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        
        R.clear();
        L.clear();
        cin >> n;
        A = vector<int>(n);
        for(auto& i : A) cin >> i;
        
        ok = 0;
        foldPaper();
        
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }    
}