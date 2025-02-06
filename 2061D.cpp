#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll numChecked = 0;
ll n;
ll ogN;

bool recurr(ll nm, map<ll, ll> &nms) {
    if (numChecked > ogN) {
        //cout << nm << ' ' << ogN << ' '<< numChecked << endl;
        return false;
    }
    if (nms[nm] > 0) {
        --nms[nm];
        --n;
        return true;
    } else if (nm > 1) {
        --numChecked;
        if (nm % 2) {
            //cout << nm << " checked odd: " << numChecked << endl;
            numChecked += 2;
            bool r1 = recurr(nm/2, nms);
            bool r2 = recurr(nm/2 + 1, nms);

            if (!r1 || !r2) {
                return false;
            } else {
                return true;
            }
        } else {
            //cout << nm << " checked: " << numChecked << endl;
            numChecked += 2;
            bool r1 = recurr(nm/2, nms);
            bool r2 = recurr(nm/2, nms);

            if (!r1 || !r2) {
                return false;
            } else {
                return true;
            }
        }
    }

    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> n >> m;

        vector<ll> a(n);
        vector<ll> b(m);

        map<ll, ll> nms;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];

            if (!nms.count(a[i])) {
                nms[a[i]] = 0;
            }
            nms[a[i]] += 1;
        }

        bool res = true;

        for (int i = 0; i<m; ++i) {
            cin >> b[i];

            numChecked = 1;
            ogN = n;
            //cout << "n left: " << n << endl;

            if (res && recurr(b[i], nms)) {
                res = true;
            } else {
                res = false;
            }
        }

        if (res && !n) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
