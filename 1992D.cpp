#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        string river;
        cin >> river;

        int pos = -1;
        bool jump = false;

        while (pos < n) {
            int lastSafe = pos;
            int lastCroc = -1;
            jump = false;

            for (int i = pos+1; i<=pos+(m+k); ++i) {
                if (river[i] == 'L' || i >= n) {
                    if ((i-pos) <= m) {
                        lastSafe = i;
                    } else {
                        if (pos + m > lastCroc && (i-pos-1) <= (k+m-1)) {
                            lastSafe = i;
                            k -= i - (pos+m);
                        }                            
                    }
                    break;
                } else if (river[i] == 'C') {
                    lastCroc = i;
                } 
            }

            if (lastSafe != pos) {
                pos = lastSafe;
            } else {
                break;
            }
        }

        if (pos >= n) {
            cout << "yES\n";
        } else {
            cout << "nO\n";
        }
    }

    return 0;
}
