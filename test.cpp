#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> ends;
    for (int i = 1; i<=500; ++i) {
        if (i % 7 == 0) {
            if (!ends.count(i%10)) {
                ends[i%10] = 1;
            } else {
                ++ends[i%10];
            }
        }
    }

    int maxe = 7;
    for (auto x: ends) {
        cout << x.first << ' ' << x.second;
        if (x.second > ends[maxe]) {
            maxe = x.first;
        }
    }

    cout << maxe << endl;

    return 0;
}
