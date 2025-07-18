#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int found = -1;
        for (int i = 0; i<s.size()-1; ++i) {
            if (s[i] == s[i+1]) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            for (int i = 0; i<26; ++i) {
                if ((char)('a'+i) != s[found] && (char)('a'+i) != s[found+1]) {
                    s = s.substr(0, found+1) + (char)('a'+i) + s.substr(found+1, s.size()-found+2);
                    break;
                }
            }

        } else {
            for (int i = 0; i<26; ++i) {
                if ((char)('a'+i) != s[s.size()-1]) { 
                    s += (char)('a'+i);
                    break;
                }
            }
        }
        cout << s << '\n';
    }

    return 0;
}
