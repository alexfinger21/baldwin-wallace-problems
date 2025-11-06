#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int c0 = 0, c2 = 0;
        for (char ch : s) {
            if (ch == '0') ++c0;
            else if (ch == '2') ++c2;
        }
        int t_min = c0;
        int t_max = c0 + c2;
        int def_remain_low = t_max + 1;
        int def_remain_high = n - k + t_min; 
        string ans;
        for (int i = 1; i <= n; ++i) {
            int low = max(t_min, i - n + k);   
            int high = min(t_max, i - 1);     
            bool possible_remain = (low <= high);
            if (!possible_remain) {
                ans.push_back('-');
            } else if (i >= def_remain_low && i <= def_remain_high) {
                ans.push_back('+');
            } else {
                ans.push_back('?');
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

