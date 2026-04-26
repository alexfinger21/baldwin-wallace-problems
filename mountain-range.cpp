#include <bits/stdc++.h>

using ll=long long;
using namespace std;

const int MAX_N = 200005;
ll tree[MAX_N * 2];

void update() {
    for (int i = 0; i<n; ++i) {

    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> dp(n);
    vector<ll> dp2(n);

    vector<int> res(n);
    vector<int> res2(n);

    vector<ll> a(n);
    map<ll, int> last_seen;

    for (int i = 0; i<n; ++i) {
        cin >> a[i];
    }

    dp[0] = a[0];
    int dp_idx = 0;
    res[0] = 1;
    
    for (int i = 1; i<n; ++i) {
        while (dp_idx >= 0 && dp[dp_idx] <= a[i]) {
            if (!last_seen.count(dp[dp_idx])) {
                last_seen[dp[dp_idx]] = i-1;
            }

            --dp_idx;
        } 

        ++dp_idx;
        dp[dp_idx] = a[i];

        res[i] = dp_idx + 1;
    }

    dp_idx = 0;
    dp2[0] = a[n-1];

    if (!last_seen.count(a[n-1]) || last_seen[a[n-1]] >= n-1) {
        res2[n-1] = 1;
    }

    for (int i = n-2; i>=0; --i) {
        while (dp_idx >= 0 && dp2[dp_idx] <= a[i]) {
            --dp_idx;
        } 

        if (!last_seen.count(a[i]) || last_seen[a[i]] >= i) {
            ++dp_idx;
            dp2[dp_idx] = a[i];
        } else {
            cout << i << ' ' << a[i] << ' ' << last_seen[a[i]] << endl;
        }

        res2[i] = dp_idx + 1;
    }

    int out = 1;


    for (int i = 0; i<n-1; ++i) {
        out = max(out, res[i] + res2[i+1]);
        if (res[i] + res2[i+1] == 9) {
            cout << i << ' ' << a[i-1] << ' ' << a[i] << ' ' << a[i+1] << endl;
            for (int i = -3; i<3; ++i) {
                cout << a[i-1] << ' ';
            }
            cout << endl;
        }
        // cout << res[i] << ' ' << res2[i+1] << endl;
    }
    
    cout << out << '\n';

    return 0;
}
