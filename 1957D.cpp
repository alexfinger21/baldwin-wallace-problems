#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int checkRange(int s, int e, vector<int> &bits) {
    int res = 0;

    for (auto b = bits.begin(); b != bits.end(); ++b) {
        //cout << s << e << *b << endl;
        if (*b >= s && *b <= e) {
            ++res;
        }
    }

    return res;
}

int findBiggestBit(int n) {
    for (int i = sizeof(int)*8 - 1; i >= 0; --i) {
        if (pow(2, i) <= n) {
            return i;
        }
    }

    return -1;
}

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c < cases; ++c) {
        int nums;
        cin >> nums;

        int count = 0;
        vector<int> numArr;

        vector<int> freq[sizeof(int) * 8];
        
        for (int num = 0; num < nums; ++num) {
            int n;
            cin >> n;
            numArr.push_back(n);
        }


        for (int c = 0; c < numArr.size(); ++c) {
            int bb = findBiggestBit(numArr[c]);
            if (bb != -1) {
                freq[bb].push_back(c);
            }
        }

        for (int i = 0; i<numArr.size(); ++i) {
            int res = numArr[i];
            for (int j = i+1; j<numArr.size(); ++j) {
                res ^= numArr[j];

                for (int z = 0; z >= sizeof(int)*8 - 1; --z) {
                    if ((int(pow(2, z)) & res) != int(pow(2, z))) {
                        count += checkRange(i, j, freq[z]);      
                    }
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}

