#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(26);

    for (int i = 0; i<26; ++i) {
        cin >> a[i];
    }

    vector<ll> dp(n);

    int longest = 0;
    int l_idx = 0;
    int num = 1;

    for (int i = 0; i<n; ++i) {
        int rem = 1e3+1;
        for (int j = i; j>=0; --j) {
            rem = min(a[s[j] - 'a'] - (i - j), rem);

            if (rem > 0) {
                dp[i] = (dp[i] + (j ? dp[j-1] : 1)) % mod;
                --rem;
                longest = max(longest, i - j + 1);
            } else {
                if (j+1 > l_idx) {
                    l_idx = i;
                    ++num;
                }
                break;
            }
        }
    }
    
    cout << dp[n-1] << '\n' << longest << '\n' << num << '\n';

    return 0;
}
