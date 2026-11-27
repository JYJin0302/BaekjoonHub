#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> A(26);
    string s;
    cin >> s;
    
    for(auto i : s) A[i-'a']++;
    for(auto i : A) cout << i << ' ';
    
}