#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        A.push_back({b, 0});
        A.push_back({a, 1});
    }
    sort(A.begin(), A.end());
   
    int cnt = 0, ans = 0;
    for(auto i:A){
        if (i.second == 0) cnt--;
        else cnt++;
        ans = max(ans, cnt);
    }
    
    cout << ans;
}