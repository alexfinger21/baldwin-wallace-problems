#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, l, h;

        cin >> n >> l >> h;

        long long res = 0;

        long long cards[n];

        for (long long i = 0; i<n; ++i) {
            long long num;
            cin >> num;

            cards[i] = num;
        }

        long long topSum = 0;
        vector<pair<int, int>> intervals;

        int first = 0;

        for (int i = 0; i<n; ++i) {
            int supaSum = cards[i] + topSum;

            while (supaSum > h) {
                supaSum -= cards[first];
                ++first;
            }

            if (supaSum >= l) {
                ++res;
                first = i+1;
                supaSum = 0;
            }

            topSum = supaSum;
        }

        cout << res << '\n';
    }

    return 0;
}
