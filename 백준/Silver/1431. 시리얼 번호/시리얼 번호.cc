#include <bits/stdc++.h>
using namespace std;


bool cmp(string a, string b){
    if (a.size() != b.size()) return a.size() < b.size();
    int xa = 0, xb = 0;
    for(auto i : a) if(i >= '0' && i <= '9') xa += i - '0';
    for(auto i : b) if(i >= '0' && i <= '9') xb += i - '0';
    
    if (xa != xb) return xa < xb;
    
    return a < b;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end(), cmp);
    
    for(auto i : A) cout << i << '\n';    
}