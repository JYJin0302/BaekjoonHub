#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return min(a.y, a.x+b.y) > min(b.y, b.x+a.y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, tot = 0;
    cin >> n;
    vector<pair<int, int>> A(n);
    
    for(auto& i : A) {
        cin >> i.x >> i.y;
        i.y += i.x;
        tot += i.x;
    }
    
    sort(A.begin(), A.end(), cmp);
    
    int ans = -1e9;
    for(auto i : A) {
        ans = max(ans, tot - i.y);
        tot -= i.x;
    }
    cout << ans;
}