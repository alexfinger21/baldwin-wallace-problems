#include <iostream>
#include <string>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int maxSub = 0;

        for (int i = 0; i<b.size(); ++i) {
            int matches = 0;



            for (int j = 0; j<a.size(); ++j) {
                if (a[j] == b[i]) {
                    ++matches;
                    ++i;
                }
            }

            i -= matches;
            maxSub = max(maxSub, matches);
        }

        cout << a.size() + b.size() - maxSub << '\n';
    }

    return 0;
}
