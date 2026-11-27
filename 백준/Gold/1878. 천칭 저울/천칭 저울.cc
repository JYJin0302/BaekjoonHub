#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int n, sz;
vector<int> A, B;

int idx[101010];

int o = 0;
void getIdx(int x) {
    if (x * 2 <= sz) getIdx(x * 2);
    idx[x] = o++;
    if (x * 2 + 1 <= sz) getIdx(x * 2 + 1);
}

void inOrder(int x) {
    //cout << "VX: " << x << ' ';
    cout << A[idx[x]] << ' ';
    if (x * 2 <= sz) inOrder(x * 2);
    if (x * 2 + 1 <= sz) inOrder(x * 2 + 1);
}

void postOrder(int x) {
    cout << B[sz - 1 - idx[x]] << ' ';
    if (x * 2 + 1 <= sz) postOrder(x * 2 + 1);
    if (x * 2 <= sz) postOrder(x* 2);
}

void fill(int x) {

    while (x >= 8 || x == 4) {
        A.push_back(x);
        A.push_back(x - 3);
        B.push_back(x - 1);
        B.push_back(x - 2);

        x -= 4;
    }

    if (x == 7) {
        A.push_back(x);
        A.push_back(x - 4);
        A.push_back(x - 5);
        B.push_back(x - 1);
        B.push_back(x - 2);
        B.push_back(x - 6);
    }

    if (x == 5) {
        A.push_back(x);
        A.push_back(x - 3);
        B.push_back(x - 1);
        B.push_back(x - 2);

    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n;

    if (n <= 3 || (n%2 == 0 && n% 4== 2)) {
        cout << -1;
        return 0;
    }

    sz = n / 2;

    fill(n);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    getIdx(1);

    inOrder(1);
    cout << '\n';
    postOrder(1);


}