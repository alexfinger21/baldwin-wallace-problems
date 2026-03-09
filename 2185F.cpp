#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, q;
        cin >> n >> q;

        vector<vector<ll>> tree(n+1);

        ll width = pow(2, n);

        ll a;
        for (int i = 0; i<pow(2, n); ++i) {
            cin >> a;
            if (width > 0) { 
                tree[i] = vector<ll>(width);
                //cout << "SUCCESS" << endl;
                //cout << width << endl;
                width /= 2;
            }
            //cout << "val of i: " << i << endl;

            tree[0][i] = a; 
            //cout << tree[0][i] << endl;
        }

        for (int i = 1; i<=n; ++i) {
            for (int j = 0; j<pow(2, n-i); ++j) {
                //cout << i << ' ' << j << endl;
                tree[i][j] = tree[i-1][j*2] ^ tree[i-1][j*2+1];
                //cout << tree[i][j] << endl;
            }
        }

        // cout << tree[n][0] << endl;


        for (int i = 0; i<q; ++i) {
            ll res = 0;
            ll b;
            ll c;

            cin >> b >> c;

            b -= 1;
            
            for (int j = 0; j<n; ++j) {
                int idx;

                if (b % 2) {
                    idx = b - 1;
                } else {
                    idx = b + 1;
                }
                
                //cout << b << ' ' << idx << ' ' << tree[j].size() << ' ' << c << endl;
                if (tree[j][idx] > c || (tree[j][idx] == c && b % 2)) {
                    res += pow(2, j);
                }  

                c ^= tree[j][idx];
                
                b /= 2;
            }

            cout << res << '\n';
        }
    }

    return 0;
}
