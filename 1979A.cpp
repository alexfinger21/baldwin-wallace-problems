#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);


        for (int i = 0; i<n; ++i) {
            cin >> arr[i];
        }
        
        int smallestMax = max(arr[0], arr[1]);

        for (int i = 1; i<n-1; ++i) {
            if (max(arr[i], arr[i+1]) < smallestMax) {
                smallestMax = max(arr[i], arr[i+1]); 
            }
        }

        cout << smallestMax - 1 << '\n';
    }

    return 0;
}
