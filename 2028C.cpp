#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n, m, v;
        cin >> n >> m >> v;

        vector<ll> a(n);
        ll total_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_sum += a[i];
        }

        // Step 1: Build mfront array (max creatures satisfied from the front)
        vector<ll> psbf(n+1, 1e9+1);
        psbf[0] = 0;
        vector<int> mfront(n, 0);
        ll s = 0;
        ll current_sum = 0;
        int creatures_from_front = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i];
            current_sum += a[i];
            if (current_sum >= v) {
                creatures_from_front++;
                current_sum = 0;
            }
            mfront[i] = creatures_from_front;
            psbf[creatures_from_front] = min(s, psbf[creatures_from_front]);

        }

        // Step 2: Build mback array (max creatures satisfied from the back)
        vector<ll> psb(n+1, 1e9+1);
        s = 0;
        vector<int> mback(n, 0);
        current_sum = 0;
        int creatures_from_back = 0;
        for (int i = n - 1; i >= 0; --i) {
            s += a[i];
            current_sum += a[i];
            if (current_sum >= v) {
                creatures_from_back++;
                current_sum = 0;
            }
            mback[i] = creatures_from_back;
            psb[creatures_from_back] = min(s, psb[creatures_from_back]);
        }

        /*
           cout << "mfront: ";
           for (int i = 0; i < n; ++i) {
           cout << mfront[i] << " ";
           }
           cout << endl;

        // Printing mback array
        cout << "mback: ";
        for (int i = 0; i < n; ++i) {
        cout << mback[i] << " ";
        }

        // Calculate prefix sum from the back

        cout << endl;
        */
        // Step 3: Calculate maximum tastiness Alice can get
        ll max_alice_sum = -1;

        // Try every possible split point
        ll prefix_sum = 0;
        for (int i = 0; i < n; ++i) {

            // Number of creatures satisfied from the front up to index i
            int front_creatures = mfront[i];

            // Remaining creatures need to be satisfied from the back
            int required_from_back = m - front_creatures;

            // Check if we can satisfy the required creatures from the back
            if (i + 1 < n && mback[i + 1] >= required_from_back && required_from_back >= 0) {
                // Calculate Alice's possible sum
                ll sum_from_front = psbf[front_creatures]; // Alice's sum from the front up to i
                ll sum_from_back = total_sum - sum_from_front; // Remaining part after index i
                ll alice_sum = sum_from_back - (required_from_back > 0 ? psb[required_from_back] : 0);
                //cout << sum_from_front << ' ' << sum_from_back << ' ' << psb[required_from_back] << ' ' << required_from_back << ' ' << alice_sum << endl;
                max_alice_sum = max(max_alice_sum, alice_sum);
            }
            prefix_sum += a[i];
        }

        // Special case: Check if we can satisfy all creatures from just the front or just the back

        cout << max_alice_sum << "\n";
    }

    return 0;
}

