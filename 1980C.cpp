#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len, l_mod;
        cin >> len;

        int og[len];
        int found[len];

        for (int i = 0; i<len; ++i) {
            cin >> og[i];
        }

        for (int i = 0; i<len; ++i) {
            cin >> found[i];

            if (found[i] == og[i]) {
                found[i] = -1;
            }
        }

        cin >> l_mod;

        map<int, int> mod;
        int last;

        for (int i = 0; i<l_mod; ++i) {
            int n;
            cin >> n;
            
            mod[n] = (mod[n] ? (mod[n] + 1) : 1);
            if (i == l_mod - 1) {
                last = n;
            } 
        }
        
        bool foundAgain = false;
        bool foundV = false;

        for (int i = 0; i<len; ++i) {
            if ((og[i] == last && found[i] == -1) || found[i] == last) {
                if (found[i] != -1) {
                    --mod[last];
                    found[i] = -1;
                }
                foundAgain = true;

                break;
            }
        }

        if (!foundAgain) {
            foundV = true;
        }

        if (!foundV) {
            for (int i = 0; i<len; ++i) {
                if (found[i] != -1) {
                    if (!mod[found[i]]) {
                        foundV = true;
                        break;
                    } else {
                        --mod[found[i]];
                    }
                }
            }
        }

        if (!foundV) {
            cout << "yES\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
