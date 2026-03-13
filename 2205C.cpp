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

        vector<int> lengths(n);
        vector<vector<ll>> users(n);
        vector<int> ignore(n);

        for (int i = 0; i<n; ++i) {
            cin >> lengths[i];
            users[i] = vector<ll>(lengths[i]);

            for (int j = 0; j<lengths[i]; ++j) {
                cin >> users[i][lengths[i] - j - 1];
            }

            set<ll> mentioned;
            for (int j = 0; j<users[i].size(); ++j) {
                if (!mentioned.count(users[i][j])) {
                    mentioned.insert(users[i][j]);
                } else {
                    users[i].erase(users[i].begin() + j);
                    --j;
                }
            }
        }

        for (int i = 0; i<n; ++i) {
            int highest = -1;

            for (int j = 0; j<n; ++j) {
                if (!ignore[j] && highest == -1) {
                    highest = j; 
                }
                if (!ignore[j] && (users[j] < users[highest])) {
                    highest = j;
                }
            }

            for (auto x : users[highest]) {
                cout << x << ' ';
            }

            ignore[highest] = true;


            for (int j = 0; j<n; ++j) {
                if (!ignore[j]) {
                    set<ll> mentioned;
                    for (auto x : users[highest]) {
                        mentioned.insert(x);
                    }

                    for (int z = 0; z<users[j].size(); ++z) {
                        if (mentioned.count(users[j][z])) {
                            users[j].erase(users[j].begin() + z);
                            --z;
                        }
                    }
                }
            }
        }

        cout << '\n';
    }

    return 0;
}
