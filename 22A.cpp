#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i<n; ++i) {
        cin >> a[i];
    }

    int m1 = a[0];

    for (auto x : a) {
        m1 = min(m1, x);
    }

    int m2 = 101;

    for (auto x : a) {
        if (x != m1 && x < m2) {
            m2 = x;
        }
    }

    if (m2 != 101) {
        cout << m2 << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
