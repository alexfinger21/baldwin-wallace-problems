#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        int a[n];
        int b[n+1];

        long long ops = 0;

        for (int i = 0; i<n; ++i) {
            int num;
            cin >> num;

            a[i] = num;
        }

        for (int i = 0; i<=n; ++i) {
            int num;
            cin >> num;
            
            if (i != n) {
                ops += abs(a[i] - num);
            }

            b[i] = num;
        }

        int closest = abs(b[n] - a[0]);

        for (int i = 1; i<n; ++i) {
            if (abs(a[i] - b[n]) < closest) {
                closest = abs(a[i] - b[n]); 
            }
        }

        for (int i = 0; i<n; ++i) {
            if (abs(b[i] - b[n]) < closest) {
                closest = abs(b[i] - b[n]); 
            }

            if (max(a[i], b[i]) > b[n] && min(a[i], b[i]) < b[n]) {
                closest = 0;
            }
        }

        ops += closest + 1;

        cout << ops << '\n';
    }

    return 0;
}
