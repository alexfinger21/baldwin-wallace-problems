#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int arr[n];

        int num = n;

        for (int i = 0; i<n; ++i) {
            if (num >= k || num > m) {
                arr[i] = num;
                --num;
            } else {
                break;
            }
        } 

        int lastN = num;
        num = 1;

        for (int i = n-lastN; i<n; ++i) {
            arr[i] = num;
            ++num;
        }

        for (int i = 0; i<n; ++i) {
            cout << arr[i] << ' ';
        }
        
        cout << '\n';
    }

    return 0;
}
