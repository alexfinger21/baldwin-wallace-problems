#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len;
        cin >> len;
        
        vector<long long> arr;

        long long c = 0;
        long long sum = 0;

        long long fn;
        cin >> fn;

        arr.push_back(fn);

        long long posLeft = 0; 
        for (int i = 1; i<len; ++i) {
            int n;
            cin >> n;
            sum += n;

            if (n > 0) {
                posLeft += n;
            }

            if ((arr[arr.size() - 1] > 0 && n < 0) || (arr[arr.size() - 1] < 0 && n > 0)) {
                arr.push_back(n);
            } else {
                arr[arr.size() - 1] += n;
            }
        }

        //cout << sum << " - SUM\n";

        long long negGained = 0;
        pair<long long, long long> biggestInd = make_pair(0, 0);
        for (int i = 0; i<arr.size(); ++i) {
            if (arr[i] > 0) {
                posLeft -= arr[i];
            } else {
                negGained += abs(arr[i]);
            }

            if (negGained + posLeft > biggestInd.first) {
                biggestInd = make_pair(negGained + posLeft, i);
            }

            //cout << posLeft << ' ' << negGained << '\n';
            //cout << "THEIR SUM: " << negGained + posLeft << endl;
        }

        for (int i = 0; i<arr.size(); ++i) {
            if (i != biggestInd.second) {
                c += arr[i];
            } else {
                c = abs(arr[i] + c);
            }
        }


        cout << abs(c) << '\n';
    }

    return 0;
}
