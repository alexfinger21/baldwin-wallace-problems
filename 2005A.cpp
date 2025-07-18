

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
     
            string chars = "aeiou";
     
            string res = "";
            
            if (n<=5) {
     
                for (int i = 0; i<n; ++i) {
                    res += chars[i];
                }
            } else {
                int perString = n/5;
                int leftOver = n - n/5*5;
                for (int i = 0; i<chars.size(); ++i) {
                    if (leftOver) {
                        res += chars[i];
                        --leftOver;
                    }
                    for (int j = 0; j<perString; ++j) {
                        res += chars[i];
                    }
                }
     
            }
     
            cout << res << '\n';
        }
     
        return 0;
    }
