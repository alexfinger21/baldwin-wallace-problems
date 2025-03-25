#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll n, m, d;
        cin >> n >> m >> d;
        
        vector<vector<int>> x_pos(n);
        vector<string> mapa(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> mapa[i];
            for (int j = 0; j < m; ++j) {
                if (mapa[i][j] == 'X') {
                    x_pos[i].push_back(j);
                }
            }
        }
        
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(2, 0)));
        
        for (int i = n - 1; i >= 0; --i) {
            const auto& current_x = x_pos[i];
            if (current_x.empty()) continue;
            
            if (i == n - 1) {
                for (int j : current_x) {
                    dp[i][j][0] = 1;
                }
            } else {
                const auto& next_x = x_pos[i + 1];
                if (!next_x.empty()) {
                    vector<ll> prefix_sum;
                    prefix_sum.push_back(0);
                    for (int k : next_x) {
                        ll val = (dp[i+1][k][0] + dp[i+1][k][1]) % MOD;
                        prefix_sum.push_back((prefix_sum.back() + val) % MOD);
                    }
                    for (int j : current_x) {
                        int delta = sqrt(d*d-1);
                        int low = j - delta;
                        int high = j + delta;
                        auto left = lower_bound(next_x.begin(), next_x.end(), low);
                        auto right = upper_bound(next_x.begin(), next_x.end(), high);
                        int l = distance(next_x.begin(), left);
                        int r = distance(next_x.begin(), right);
                        ll sum = (prefix_sum[r] - prefix_sum[l] + MOD) % MOD;
                        dp[i][j][0] = sum;
                    }
                }
            }
            
            if (!current_x.empty()) {
                vector<ll> prefix_sum;
                prefix_sum.push_back(0);
                for (int k : current_x) {
                    prefix_sum.push_back((prefix_sum.back() + dp[i][k][0]) % MOD);
                }
                for (int idx = 0; idx < current_x.size(); ++idx) {
                    int j = current_x[idx];
                    int low = j - d;
                    int high = j + d;
                    auto left = lower_bound(current_x.begin(), current_x.end(), low);
                    auto right = upper_bound(current_x.begin(), current_x.end(), high);
                    int l = distance(current_x.begin(), left);
                    int r = distance(current_x.begin(), right);
                    ll total = (prefix_sum[r] - prefix_sum[l] + MOD) % MOD;

                    if (j >= low && j <= high) {
                        total = (total - dp[i][j][0] + MOD) % MOD;
                    }
                    dp[i][j][1] = total;
                }
            }
        }
        
        ll result = 0;
        for (int j : x_pos[0]) {
            result = (result + dp[0][j][0] + dp[0][j][1]) % MOD;
        }
        cout << result << '\n';
    }
    
    return 0;
}
