#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> A(101, -1);
    A[1] = 0;

    vector<int> path(101);
    for (int i = 1; i <= 100; i++) path[i] = i;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        int a, b;
        cin >> a >> b;

        path[a] = b;
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {

        int a = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            if (a + i <= 100 && A[path[a + i]] == -1) {
                A[path[a + i]] = A[a] + 1;
                q.push(path[a + i]);
            }
        }
    }

    cout << A[100];
}