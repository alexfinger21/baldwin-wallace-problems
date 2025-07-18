#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        char trump;
        cin >> trump;

        vector<vector<int>> cards(4);

        map<char, int> suits;

        suits['C'] = 0;
        suits['D'] = 1;
        suits['H'] = 2;
        suits['S'] = 3;

        vector<char> i_s = {'C', 'D', 'H', 'S'};

        for (int i = 0; i<2*n; ++i) {
            char r;
            cin >> r;
            char c;
            cin >> c;

            cards[suits[c]].push_back(r - '0');
        }

        /*
        for (auto x : cards) {
            for (auto z : x) {
                cout << z << ' ';
            }

            cout << endl;
        }
        */
        
        int strays = 0;

        for (int i = 0; i<4; ++i) {
            if (i != suits[trump]) {
                strays += cards[i].size() % 2;
            }
        }

        if (strays > cards[suits[trump]].size()) {
            cout << "IMPOSSIBLE\n";
        } else {
            int tIdx = 0;
            for (int i = 0; i<4; ++i) {
                if (i != suits[trump]) {
                    for (int j = 0; j<(int)(cards[i].size())-1; j+=2) {
                        cout << min(cards[i][j], cards[i][j+1]) << i_s[i] << ' ' << max(cards[i][j], cards[i][j+1]) << i_s[i] << '\n';
                    }

                    if (cards[i].size() % 2) {
                        cout << cards[i][cards[i].size() - 1] << i_s[i] << ' ' << cards[suits[trump]][tIdx] << trump << '\n';
                        ++tIdx;
                    }
                }
            }

            for (int i = tIdx; i<(int)(cards[suits[trump]].size()) - 1; i += 2) {
                cout << min(cards[suits[trump]][i], cards[suits[trump]][i+1]) << trump << ' ' << max(cards[suits[trump]][i], cards[suits[trump]][i+1]) << trump << '\n';
            }
        }
    }

    return 0;
}
