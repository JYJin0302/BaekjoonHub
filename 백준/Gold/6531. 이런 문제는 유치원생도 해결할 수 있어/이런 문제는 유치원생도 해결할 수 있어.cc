#include <bits/stdc++.h>
using namespace std;

string s;
int isList[201][201];

bool isAtom(int l);
bool isElement(int l, int r);
int sList(int l, int r);
bool isSet(int l, int r);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        
        cin >> s;
        memset(isList, -1, sizeof(isList));
        
        cout << "Word #" << i << ": ";
        if (isSet(0, s.size()-1)) cout << "Set\n";
        else cout << "No Set\n";
    }
}
bool isAtom(int l){
    return s[l] == '{' || s[l] == '}' || s[l] == ',';
}
bool isElement(int l, int r){
    if (l == r && isAtom(l)) return 1;
    if (isSet(l, r)) return 1;
    return 0;
}

int sList(int l, int r){
    if (isList[l][r] != -1) return isList[l][r];
    
    if (r + 1 == l) return isList[l][r] = 1;
    if (l > r) return isList[l][r] = 0;
     
    if (isElement(l, r)) return isList[l][r] = 1;
    for (int i = l+1; i < r; i++){
        if (s[i] == ',' && isElement(l, i-1) && sList(i+1, r) == 1) return isList[l][r] = 1;
    }
    return isList[l][r] = 0;
}
bool isSet(int l, int r){
    return s[l] == '{' && s[r] == '}' && sList(l+1, r-1) == 1;
}