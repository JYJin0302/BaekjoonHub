#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b) {

    vector<vector<int>> res(a.size(), vector<int>(a[0].size()));
    for (int k = 0; k < a.size(); k++) {
        for (int i = 0; i < a.size(); i++) {
            int temp = 0;
            for (int j = 0; j < a.size(); j++) {
                temp += a[k][j] * b[j][i];
            }
            if (temp != 0) temp = 1;
            res[k][i] = temp;
        }
    }

    return res;
}

vector<vector<vector<int>>> A;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<int>> base(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        base[i][a] = 1;
        base[i][b] = 1;
    }
    
    vector<pair<int, int>> order;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        order.push_back({a, b});
    }
    
    
    k--;
    int cnt = 1;
    ll size = 1;
    while (size <= k) {
        size *= 2;
        cnt++;
    }
    cnt--;    
    
    if (k == 0){
        for (auto i : order){
            int a, b;
            tie(a, b)=  i;
            if (base[a][b] == 1) cout << "death\n";
            else cout << "life\n";
        }
        return 0;
    }
    
    vector<vector<vector<int>>> A(cnt);
    vector<int> bb(cnt);
    for (int i = 0; i < cnt; i++) {
        bb[i] = k % 2;
        k /= 2;
    }

    A[0] = base;
    
    for (int i = 1; i < cnt; i++) {
        A[i] = mult(A[i - 1], A[i - 1]);
    }

    vector<vector<int>> ans = A[0];
    for (int i = 0; i < cnt; i++) {
        if (bb[i] == 1) ans = mult(ans, A[i]);
    }

    for (int i = 0; i < m; i++){
        int a, b;
        tie(a, b) = order[i];
        if (ans[a][b] == 1) cout << "death\n";
        else cout << "life\n";
    }

}