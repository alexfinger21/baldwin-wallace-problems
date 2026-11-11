#include <algorithm>
#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int l, n;
        cin >> l >> n;

        vector<vector<int>> schedules(n);

        vector<int> res(1440);

        for (int i = 0; i<n; ++i) {
            int sch;
            cin >> sch;

            schedules[i] = vector<int>(sch*2);

            for (int j = 0; j<sch; ++j) {
                cin >> schedules[i][j*2];
                cin >> schedules[i][j*2+1];
            }
        }

        for (int i = 1; i<n; ++i) {
            for (int j = 0; j<schedules[0].size()/2; ++j) {
                int start = schedules[i][j*2 - 1] - 1;
                int end = schedules[i][j*2 + 1] - 1;

                if (res[end]) {
                    end = res[end - 1];
                } 

                if (res[start]) {
                   res[start] = end;
                }
            }
        }
    }

    return 0;
}
