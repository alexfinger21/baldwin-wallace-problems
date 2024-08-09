#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        string n;
        cin >> n;

        vector<string> answers;

        for (int a = 1; a<=10000; ++a) {
            int minB = n.size()*a-6; //at the smallest b the number can't go over 6 digits, strictly less than 10^6 b/c highest a*n == 10^6 - b which is at least 1
            int maxB = n.size()*a-1; //b can't leave 0 characters left

            for (int b = max(1, minB); b<=maxB; ++b) {
                string comp = "";

                for (int i = 0; i<n.size()*a-b; ++i) {
                    comp += n[i % n.size()];
                }

                if (comp == to_string(stoi(n)*a-b)) {
                    answers.push_back(to_string(a) + ' ' + to_string(b));
                }
            }
        }

        cout << answers.size() << '\n';

        for (auto x : answers) {
            cout << x << '\n';
        }
    }

    return 0;
}
