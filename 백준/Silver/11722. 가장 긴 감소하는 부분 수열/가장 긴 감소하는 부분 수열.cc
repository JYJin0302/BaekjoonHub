#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> base(n);
    for (auto& i : base) cin >> i;

    vector<int> lower(n);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (base[j] < base[i]) {
                lower[i] = max(lower[i], lower[j]);
            }
        }
        lower[i]++;
    }

    cout << *max_element(lower.begin(), lower.end());
}