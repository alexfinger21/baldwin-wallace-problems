#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <queue>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len, updates;
        cin >> len >> updates;

        int res[updates];

        string s, c;
        cin >> s;

        priority_queue<int> pq;

        for (int i = 0; i<updates; ++i) {
            int n;
            cin >> n;
            pq.push(n * -1);
        }

        cin >> c;

        set<pair<char, int>> charSet;

        for (int i = 0; i<updates; ++i) {
            charSet.insert(make_pair(c[i], i));
        }

        int lastLatest = -1;
        auto finish = charSet.end();

        for (auto i = charSet.begin(); i!=finish; ++i) {
            int latest = pq.top();
            pq.pop();
            latest = latest*-1 - 1;


            if (lastLatest == latest) {
                finish--;
                --i;
            } else {
                s[latest] = i->first;
            }
            lastLatest = latest;

        }

        /* 
        for (int i = 0; i<updates; ++i) {
            cout << res[i] << endl;
            s[res[i]] = c[i];
        }
        */

        cout << s << '\n';
    }

    return 0;
}
