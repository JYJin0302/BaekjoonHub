#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        string func, arr;
        int n;
        cin >> func >> n >> arr;

        vector<int> A;
        string num = "";
        for (char i : arr) {
            if (i >= '0' && i <= '9') num += i;
            else if (num != "") {
                A.push_back(stoi(num));
                num = "";
            }
        }

        bool error = false;
        bool reversed = false;
        int l = 0, r = n - 1;
        for (char i : func) {
            switch(i) {
            case 'R':
                reversed ^= 1;
                break;
            case 'D':
                if (l > r) {
                    error = true;
                    break;
                }
                if (reversed) r--;
                else l++;

                
            }
        }
        if (error) cout << "error\n";
        else {
            cout << '[';
            if (reversed) {
                for (int i = r; i >= l; i--) {
                    if (i != r) cout << ',';
                    cout << A[i];
                }
            }
            else {
                for (int i = l; i <= r; i++) {
                    if (i != l) cout << ',';
                    cout << A[i];
                }
            }
            cout << "]\n";
        }
    }
}