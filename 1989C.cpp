#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int bothNeg = 0, bothPos = 0, r1 = 0, r2 = 0, person1[n];

        for (int i = 0; i<n; ++i) {
            int num;
            cin >> num;

            person1[i] = num;
        }
        
        for (int i = 0; i<n; ++i) {
            int rate1 = person1[i], rate2;
            cin >> rate2;

            if (rate1 == 1) {
                if (rate2 != 1) {
                    ++r1;
                } else {
                    ++bothPos;
                }
            } else {
                if (rate2 == 1) {
                    ++r2;
                } else if (rate2 == -1) {
                    if (rate1 == -1) {
                        ++bothNeg;
                    }
                }
            }
        }

        int maxRating = max(r1, r2), minRating = min(r1, r2);

        if (bothNeg < maxRating-minRating) {
            maxRating -= bothNeg;
            bothNeg = 0;
        } else {
            bothNeg -= maxRating-minRating;
            maxRating -= maxRating-minRating;
        }

        maxRating -= bothNeg / 2;
        minRating -= bothNeg / 2;

        if (bothNeg % 2 == 1) {
            if (bothPos > 0) {
                --bothPos;
            } else {
                minRating -= 1;
            }
        }

        if (bothPos < maxRating - minRating) {
            minRating += bothPos;
            bothPos = 0;
        } else {
            bothPos -= maxRating - minRating;
            minRating += maxRating - minRating;
        }

        cout << min(minRating + bothPos/2, maxRating + bothPos/2) << '\n';
    }
    
    return 0;
}
