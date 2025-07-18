#include <iostream>
#include <set>
#include <utility>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int h, n;
        long long turns = 0;

        cin >> h >> n;

        int a[n], c[n];


        set<pair<long long, int>> dmg;    

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }
        
        for (int i = 0; i<n; ++i) {
            cin >> c[i];

            dmg.insert(make_pair(1, i));
        }

        while (h > 0) {
            auto firstHit = dmg.begin();

            h -= a[firstHit->second];
            turns = firstHit->first;

            //cout << "FIRST: " << turns << " HEALTH: " << h << endl;


            dmg.insert(make_pair(c[firstHit->second] + turns, firstHit->second));
            dmg.erase(firstHit);
        }

        cout << turns << '\n';
    }

    return 0;
}
