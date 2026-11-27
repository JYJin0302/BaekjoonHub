#include <bits/stdc++.h>
using namespace std;

int ind;
string s;


bool checkl() {
    if (ind + 1 == s.size() || s[ind + 1] == '1') return false;
    if (ind + 2 >= s.size() || s[ind + 2] == '1') return false;
    ind += 3;
    while (s[ind] == '0' && ind < s.size()) ind++;
    if (ind == s.size()) return false;
    while (s[ind] == '1' && ind < s.size()) ind++;
    return true;
}
bool checkr() {
    if (ind + 1 == s.size() || s[ind + 1] == '0')
        return false;
    ind += 2;
    return true;
}


void solve() {
   
    ind = 0;
    while (ind < s.size()) {
        if (s[ind] == '0') {
            if (!checkr()) {
                ind--;
                if (ind == -1 || s[ind-1] == '0' || !checkl()) {
                    cout << "NO\n";
                    return;
                }
            }
        }
        else {
            if (!checkl()) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;

        solve();
    }
    


}