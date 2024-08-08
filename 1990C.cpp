#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> arr(n);

        ll res = 0;
        map<ll, ll> occur;

        for (ll i = 0; i<n; ++i) {
            ll num;
            cin >> num;
            arr[i] = num;
            res += num;
            if (occur.find(num) == occur.end()) {
                occur[num] = i;
            }
        }


        vector<ll> b(n);
        map<ll, ll> occur_b;
        ll biggestDub = 0, idx = 0;

        for (ll i = 0; i<n; ++i) {
            if (occur[arr[i]] < i && arr[i] > biggestDub) {
                biggestDub = arr[i];
                idx = i;
                occur_b[arr[i]] = i;
            }
            b[i] = biggestDub;
            res += biggestDub;
        }

        /*
           for (auto x : b) {
           cout << x << ' ';
           }
           cout << endl;
        //*/
        biggestDub = 0, idx = 0;
        for (ll i = 1; i<n; ++i) {
            if (occur_b[b[i]] < i && b[i] > biggestDub) {
                if (i - idx > 1) {
                    res += biggestDub*(i-idx)*(n-i) + (i-idx)*(i-idx+1)/2*biggestDub; //n*(n+1)/2
                } else {
                    res += biggestDub;
                }
                biggestDub = b[i];
                idx = i;
            }
            //cout << res << endl;
            //res += biggestDub*(i-idx+1);

        }
        res += (n-idx)*(n-idx+1)/2*biggestDub; //n*(n+1)/2

       cout << res << endl;
    }

    return 0;
}
