#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    vector<int> base(10);
    for (char i : s){
        base[i - '0']++;
    }
    base[6] = (base[6] + base[9] + 1)/2;
    cout << *max_element(base.begin(), base.end()-1);
}