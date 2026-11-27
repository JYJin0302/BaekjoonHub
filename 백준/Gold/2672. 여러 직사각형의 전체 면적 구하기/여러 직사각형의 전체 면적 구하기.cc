#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> A;
    vector<tuple<int, int, int, int >> B;
    double a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        B.push_back({ a * 10, b * 10, a * 10 + c * 10, b * 10 + d * 10 });
        A.push_back(a * 10);
        A.push_back(a * 10 + c * 10);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int prex = 0, prelen = 0;
    int ans = 0;
    
    for (int i = 0; i < A.size(); i++) {

        int curr = A[i];
        
        int x, y, z, w;

        ans += prelen * (curr - prex);

        vector<pair<int, int>> save;
        for (auto k : B) {
            tie(x, y, z, w) = k;

            if (x <= curr && z > curr) save.push_back({ y, w });
        }
        sort(save.begin(), save.end());

        int temp = 0, l = 0, r = 0;
        for (auto k : save) {
            tie(y, w) = k;
            if (y <= r) r = max(r, w);
            else {
                temp += r - l;
                l = y;
                r = w;
            }
        }
        temp += r - l;

        prelen = temp;
        prex = curr;
        
    }
    if (ans % 100 == 0 )cout << ans / 100;
    else {
        cout << fixed;
        cout.precision(2);
        cout << ans / 100.0;
    }
}