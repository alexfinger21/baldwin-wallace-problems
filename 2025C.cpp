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

        vector<ll> cards(n);
        
        for (int i = 0; i<cards.size(); ++i) {
            cin >> cards[i];
        }

        sort(cards.begin(), cards.end(), less<ll>());
        
        vector<int> idx;
        vector<int> count;
        int indx = 0;
        auto up_res = upper_bound(cards.begin(), cards.end(), cards[indx]);

        while (up_res != cards.end()) {
            //cout << up_res - cards.begin() << endl;
            idx.push_back(up_res - cards.begin());
            count.push_back(up_res - cards.begin() - indx);
            indx = up_res - cards.begin();
            up_res = upper_bound(cards.begin(), cards.end(), cards[indx]);
        }

        idx.push_back(cards.size());
        count.push_back(cards.end() - cards.begin() - indx);

        /*
        for (auto x : cards) {
           cout << x << ' ';
        }

        cout << endl;
        for (auto x : idx) {
            cout << x << '_';
        } 
        cout << endl;
        for (auto x : count) {
            cout << x << '+';
        }
        cout << endl;
        //*/

        int last = 0;
        ll res = 0;
        ll current = count[last];

        for (int i = 1; i<idx.size(); ++i) {
            if ((i-last) < k && (cards[idx[i] - 1] - cards[idx[i-1] - 1]) <= 1) {
                current += count[i];
            } else {
                res = max(res, current);
                while ((i - last) >= k || (cards[idx[i]-1] - cards[idx[max(last, i-1)] - 1]) > 1) {
                    current -= count[last];
                    //cout << '-' << cards[idx[i]-1] << ' ' << count[last] << endl;
                    ++last;
                }

                current += count[i];
            }
        }
        res = max(res, current);

        cout << res << '\n';


    }

    return 0;
}
