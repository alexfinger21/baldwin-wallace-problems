#include <iostream>
#include <map>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len;
        long long coins = 0;

        cin >> len;

        map<long long, long long> unsorted;

        long long prev = -1;
        long long saiz = 0;

        for (int i = 0; i<len; ++i) {
            long long n;
            cin >> n;

            if (n < prev) {
                ++unsorted[prev-n];
            } else {
                prev = n;
            }
        }

        for (auto x : unsorted) {
            saiz += x.second;
        }

        prev = 0;

        while (unsorted.size() > 0) {
            auto first = unsorted.begin();
            //cout << first->first << ' ' << prev << endl;
            coins += (saiz+1)*(first->first - prev);
            prev = first->first; 
            saiz -= first->second;
            unsorted.erase(first);
        }

        cout << coins << '\n';
    }

    return 0;
}
