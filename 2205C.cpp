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

        set<ll> vals;

        for (int i = 0; i<n; ++i) {
            for (int i = 0; i<users.size(); ++i) {
                for (int j = 0; j<users[i].size(); ++j) {
                    if (vals.count(users[i][j])) {
                        // cout << "found! " << users[i][j] << endl;
                        users[i].erase(users[i].begin() + j);
                        --j;
                    }
                }

                if (!users[i].size()) {
                    users.erase(users.begin() + i);
                    --i;
                }
            }

            sort(users.begin(), users.end(), [](const auto& v1, const auto& v2) {
                    for (int i = 0; i<min(v1.size(), v2.size()); ++i) {
                    if (v1[i] > v2[i]) { 
                        /*
                        cout << "biggest: " << endl;
                        for (auto x : v1) {
                            cout << x << ' ';
                        }
                        cout << endl;
                        for (auto x : v2) {
                        cout << x << ' ';
                        }
                        cout << endl;
                        cout << "---";
                        cout << endl;
                        */
                       return false; 
                    }

                    if (v1[i] < v2[i]) {
                    /*
                    cout << "biggest: " << endl;
                    for (auto x : v2) {
                    cout << x << ' ';
                    }
                    cout << endl;
                    for (auto x : v1) {
                        cout << x << ' ';
                    }
                    cout << endl;
                    cout << "---";
                    cout << endl;
                    */
                        return true; 
                    }
                    }


                return (v1.size() - v2.size()) > 0 ? true : false;
            });
            // cout << "----------" << endl;

            if (users.size()) {
                for (int j = 0; j<users[0].size(); ++j) {
                    if (!vals.count(users[0][j])) {
                        cout << users[0][j] << ' ';
                        vals.insert(users[0][j]);
                    }
                }    

                users.erase(users.begin());
            }
        }

        cout << '\n';
    }

    return 0;
}
