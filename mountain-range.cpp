#include <bits/stdc++.h>

using ll=long long;
using namespace std;

const int MAX_N = 200005;
ll tree[MAX_N * 2];
ll n;

void update(int idx, int val) {
    idx += n;

    for (tree[idx] = val; idx>1; idx >>= 1) {
        tree[idx >> 1] = max(tree[idx], tree[idx ^ 1]); 
    }
}

ll query(int l, int r) {
    ll res = 0;

    for (l += n, r += n; l<r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, tree[l++]);
        if (r & 1) res = max(res, tree[--r]);
    }

    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<ll> h(n);
    vector<ll> L(n, -1), R(n, n);
    vector<ll> st;

    for (int i = 0; i<n; ++i) {
        cin >> h[i];
    }

    for (int i = 0; i<n; ++i) {
        while (!st.empty() && h[st.back()] < h[i]) {
            st.pop_back();
        }

        if (!st.empty()) {
            L[i] = st.back();
        }

        st.push_back(i);
    }

    st.clear();

    for (int i = n-1; i>=0; --i) {
        while (!st.empty() && h[st.back()] < h[i]) {
            st.pop_back();
        }

        if (!st.empty()) {
            R[i] = st.back();
        }

        st.push_back(i);
    }

    vector<pair<ll, int>> h_pairs(n);

    for (int i = 0; i<n; ++i) {
        h_pairs[i] = {h[i], i};
    }

    sort(h_pairs.begin(), h_pairs.end());

    vector<ll> dp(n);

    ll res = 1;

    for (int i = 0; i<n;) {
        int j = i;

        while (j < n && h_pairs[j].first == h_pairs[i].first) {
            int idx = h_pairs[j].second;
            dp[idx] = 1 + query(L[idx] + 1, R[idx]);
            // cout << "query res: " << dp[idx] << endl;

            res = max(dp[idx], res);

            ++j;
        }

        for (int k = i; k<j; ++k) {
            update(h_pairs[k].second, dp[h_pairs[k].second]);
        }

        i = j;
    }

    cout << res << '\n';

    return 0;
}

