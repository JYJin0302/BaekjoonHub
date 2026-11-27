#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n, k, a;
    cin >> t;
    while (t--) {
        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        map<int, int> maxp, minp;

        cin >> n;
        while (n--) {
            char i;
            cin >> i >> k;

            switch (i) {
            case 'I':
                maxpq.push(k);
                minpq.push(k);
                maxp[k]++;
                minp[k]++;

                break;

            case 'D':

                if (k == -1 && !minpq.empty()) {
                    a = minpq.top();
                    minp[a]--;
                    minpq.pop();
                }
                if (k == 1 && !maxpq.empty()) {
                    a = maxpq.top();
                    maxp[a]--;
                    maxpq.pop();
                }

            }

            while (!maxpq.empty()) {
                k = maxpq.top();

                if (maxp[k] > minp[k]) maxp[k]--;
                else if (maxp[k] <= minp[k]) break;
                maxpq.pop();
            }
            while (!minpq.empty()) {
                k = minpq.top();

                if (minp[k] > maxp[k]) minp[k]--;
                else if (maxp[k] >= minp[k]) break;
                minpq.pop();
            }
        }
        if (!maxpq.empty() && !minpq.empty()) cout << maxpq.top() << ' ' << minpq.top() << '\n';
        else cout << "EMPTY\n";
    }

}