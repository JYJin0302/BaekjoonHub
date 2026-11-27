#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2){
   return s1 + s2 > s2 + s1;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<string> A(n);
    for(auto&i : A) cin>>i;
    
    sort(A.begin(), A.end(), cmp);
    
    if (A[0] == "0" && A[n-1] == "0") cout << 0;
    else for(auto i : A) cout << i;
}