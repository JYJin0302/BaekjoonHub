#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;



void solve(){
    
    vector<int> A(5);
    cout << "1 0 0" << endl;
    cin >> A[0];

    cout << "0 1 0" << endl;
    cin >> A[1];

    cout << "0 0 1" << endl;
    cin >> A[2];

    cout << "1 1 1" << endl;
    cin >> A[3];

    cout << "1 2 4" << endl;
    cin >> A[4];

    if(A[0] + A[1] + A[2] == A[3] || A[0] + 2*A[1] + 4*A[2] == A[4]){
        cout << A[0] << ' '<< A[1] << ' '<< A[2] << endl;
        return;
    }

    if (A[1] + 3*A[2] + A[3] == A[4]) {
        cout << A[3] - A[1] - A[2] << ' '<< A[1] << ' '<< A[2] << endl;
        return;
    }

    if(2*A[3] - A[0] + 2 * A[2] == A[4]){
        cout << A[0] << ' ' << A[3] - A[0] - A[2] << ' '<< A[2] << endl;
        return;
    }

    if(4 * A[3] - 3*A[0] - 2 * A[1] == A[4]){
        cout << A[0]<< ' '<< A[1] << ' '<< A[3] - A[0] - A[1] << endl;
        return;
    }

    assert(0);

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}