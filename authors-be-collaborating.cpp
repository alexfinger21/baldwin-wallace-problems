#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int og_t = t;

    while (t--) {
        int b;
        cin >> b;

        vector<vector<string>> authors;

        for (int i = 0; i<b; ++i) {
            string t;
            cin >> t;

            int n;
            cin >> n;

            vector<string> aths(n);

            for (int j = 0; j<n; ++j) {
                cin >> aths[j];
            }

            authors.push_back(aths); 
        }

        int r;
        cin >> r;

        cout << "Case " << og_t-t << ": " << endl;
        for (int i = 0; i<r; ++i) {
            string p, l;
            cin >> p >> l;
            int d = 0;
            set<int> v0;
            set<int> v1;

            for (auto a : authors) {
                auto f_r = find(a.begin(), a.end(), p); 
                if (f_r != a.end()) {
                    v0.insert(find(authors.begin(), authors.end(), a) - authors.begin());
                }
            }

            for (auto a : authors) {
                auto f_r = find(a.begin(), a.end(), l); 

                if (f_r != a.end()) {
                    v1.insert(find(authors.begin(), authors.end(), a) - authors.begin());
                }
            }
            
            bool found = false;
            for (auto at : v0) {
                if (v1.find(at) != v1.end()) {
                    found = true;
                    break;
                }
            }


            while (!found) {
                int og_s0 = v0.size();
                int og_s1 = v1.size();
                ++d;

                vector<int> neew;

                for (auto a : authors) {
                    for (auto v : v0) {
                        for (auto v_x : authors[v]) {
                            auto f_r = find(a.begin(), a.end(), v_x); 
                            if (f_r != a.end()) {
                                neew.push_back(find(authors.begin(), authors.end(), a) - authors.begin());
                            }
                        }
                    }
                }
                
                for (auto x : neew) {
                    v0.insert(x);
                }

                if (og_s0 == v0.size() && og_s1 == v1.size()) {
                    d = -1;
                    break;
                }

                for (auto at : v0) {
                    if (v1.find(at) != v1.end()) {
                        found = true;
                        break;
                    }
                }
            }
            if (d != -1) {
                cout << "Collaboration Score: " << d << endl;
            } else {
                cout << "No connection" << endl;
            }
        }
    }

    return 0;
}
