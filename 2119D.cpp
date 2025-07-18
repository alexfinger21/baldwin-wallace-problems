#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        int64 m;
        cin >> n >> m;

        // dp[r] = sum of weight‑products for exactly r removals after current i
        // cnt[r] = count of ways for exactly r removals after current i
        vector<int64> dp(n+2, 0), cnt(n+2, 0);
        vector<int64> new_dp(n+2, 0), new_cnt(n+2, 0);

        // base: i=0, zero removals, one empty way of weight 1
        cnt[0] = 1;
        dp[0]  = 1;

        for(int i = 0; i < n; i++){
            // clear next‑step arrays
            fill(new_cnt.begin(), new_cnt.end(), 0);
            fill(new_dp.begin(),  new_dp.end(),  0);

            // precompute the prefix sums 1+2+...+(i+1) and 1^2+2^2+...+(i+1)^2
            int64 ip1 = i + 1;
            // sum1 = (i+1)*(i+2)/2 exactly
            __int128 tmp1 = (__int128)ip1 * (ip1 + 1);
            int64 sum1 = int64(tmp1 / 2 % m);
            // sum2 = (i+1)*(i+2)*(2*(i+1)+1)/6 exactly
            __int128 tmp2 = (__int128)ip1 * (ip1 + 1) * (2*ip1 + 1);
            int64 sum2 = int64(tmp2 / 6 % m);

            for(int r = 0; r <= i; r++){
                int64 c = cnt[r];
                int64 w = dp[r];
                if(c == 0 && w == 0) continue;

                // 1) skip removal at step i+1
                new_cnt[r] = (new_cnt[r] + c) % m;
                new_dp[ r] = (new_dp[ r] + w) % m;

                // 2) remove one token at step i+1
                int alive_total = n - r;             // how many tokens remain alive
                int64 C = min<int64>(ip1, alive_total);  // how many eligible positions ≤ i+1

                // update counts
                new_cnt[r+1] = (new_cnt[r+1] + c * C) % m;

                // update weighted sum of products
                // old products w each get multiplied by sum1
                // plus new single-token contributions c * sum2
                int64 add = ( (w * sum1) % m + (c * sum2) % m ) % m;
                new_dp[r+1] = (new_dp[r+1] + add) % m;
            }

            // move to next step
            swap(cnt, new_cnt);
            swap(dp,  new_dp);
        }

        // answer is sum of dp[r] over r=0..n
        int64 ans = 0;
        for(int r = 0; r <= n; r++){
            ans = (ans + dp[r]) % m;
        }
        cout << ans << "\n";
    }

    return 0;
}

