#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n][n];

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                char num;
                cin >> num;

                arr[i][j] = num - '0';
            }
        }

        for (int i = 0; i<n; i+=k) {
            for (int j = 0; j<n; j+=k) {
                cout << arr[i][j];
            }

            cout << '\n';
        }
    }

    return 0;
}
