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

        vector<int> arr1(n);
        vector<int> arr2((int)(log2(n))*2+1);

        int idx = 0;
        int idx2 = 0;

        for (int i = 2; i<=(pow(2, (int)(log2(n))-(n%2 ? 0 : 1))); i*=2) {
            int n1 = min(n-1, (i != 2 || n == 5) ? i+1 : i);
            int n2 = i-1;
            for (int j = max(1, arr2[max(0, idx2-1)])+1; j<n2; ++j) {
                arr1[idx] = j;
                ++idx;
            }

            if (arr2[max(0, idx2-1)] != n2) {
                arr2[idx2] = n2;
                ++idx2;
            } else {
                n2 = 0;
            }
            arr2[idx2] = n1;
            ++idx2;
            for (int j = arr2[idx2-2]+1; j<n1; ++j) {
                arr1[idx] = j;
                ++idx;
            }
        }
        
        if (!(n%2)) {
            int n2 = pow(2, (int)(log2(n)))-1;
            for (int j = max(1, arr2[max(0, idx2-1)])+1; j<n2; ++j) {
                arr1[idx] = j;
                ++idx;
            }

            arr2[idx2] = n2;
            ++idx2;

            for (int i = n2+1; i<n; ++i) {
                arr1[idx] = i;
                ++idx;
            }
        }
        if (arr2[idx2-1] != n) {
            if (n%2) {
                for (int j = max(1, arr2[max(0, idx2-1)])+1; j<n; ++j) {
                    arr1[idx] = j;
                    ++idx;
                }
            }
            arr2[idx2] = n;
        }

        int k = 0;
        int mov = 1;
        string outp = "";
        for (auto x : arr1) {
            if (x == 0) {
                break;
            }
            if (mov % 2) {
                k &= x;
            } else {
                k |= x;
            }
            ++mov;
           outp += to_string(x);
           outp += ' ';
        }
        for (auto x : arr2) {
            if (x == 0) {
                break;
            }
            if (mov % 2) {
                k &= x;
            } else {
                k |= x;
            }
            ++mov;
           outp += to_string(x);
           outp += ' ';
        }
        cout << k << '\n';
        cout << outp << '\n';
    }

    return 0;
}
