#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> base(n);
    for (auto& i : base) cin >> i;
    sort(base.begin(), base.end());
    
    cout << base.front() * base.back();
}