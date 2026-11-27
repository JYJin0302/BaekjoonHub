#include<bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int curr = B[i];
        int ix = find(A.begin(), A.end(), curr) - A.begin();

        //assert(A[ix] == curr);

        while (ix > i) {
            if (abs(A[ix - 1] - A[ix]) < 2) {
                cout << -1;
                return 0;
            }
            ans.push_back(ix - 1);
            swap(A[ix - 1], A[ix]);
            ix--;
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i+1 << ' ';
}
