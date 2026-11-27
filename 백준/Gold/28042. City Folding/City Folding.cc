#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    ll n, p, h;

    cin >> n >> p >> h;

    vector<ll> p2(n+1);

    p2[0] = 1;

    for(int i = 1; i <= n; i++){

        p2[i] = p2[i-1]*2;

    }

    vector<int> res;

    ll th = h;

    for(int i = n; i >= 1; i--){

        ll cc = p2[i-1];

        if (cc < th){

            th = cc*2 - th + 1;

            res.push_back(1);

        }

        else{

            res.push_back(0);

        }

    }

    reverse(res.begin(), res.end());

    ll l = 1, r = p2[n], pos = p;

    for(int i : res){

        ll mid = (l+r)/2;

        if (i == 0){

            if (pos <= mid){

                cout <<'R';

                r = mid;

            }

            else{

                cout << 'L';

                l = mid+1;

            }

        }

        else{

            if (pos <= mid){

                cout << 'L';

                pos = 2*mid - pos + 1;

                l = mid+1;

            }

            else{

                cout << 'R';

                pos = 2*mid - pos + 1;

                r = mid;

            }

        }

    }

    return 0;

}

