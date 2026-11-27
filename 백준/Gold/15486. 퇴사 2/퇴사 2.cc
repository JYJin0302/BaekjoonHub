#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n + 1);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (i > 0) A[i] = max(A[i], A[i - 1]);

        if (i + a <= n) {
            A[i + a] = max(A[i + a], A[i] + b);
        }
    }
    
    cout << *max_element(A.begin(), A.end());
}
