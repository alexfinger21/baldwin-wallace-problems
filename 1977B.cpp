#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int cc;
    cin >> cc;

    for (int c = 0; c<cc; ++c) {
        int len;
        cin >> len;

        vector<int> res;

        int arrLen = log2(len)+1;

        if (arrLen == 1) {
            cout << '1' << '\n';
            cout << "1 " << '\n';
            continue;
        }

        for (int i = pow(2, (int)(log2(len))); i>0; i /= 2) {
            if (len < i) {
                res.push_back(0);
            } else {
                len -= i;
                res.push_back(1);
            }
        }

        for (int i = 0; i<arrLen/2; ++i) {
            res[i] ^= res[arrLen - i - 1];
            res[arrLen - i - 1] ^= res[i];
            res[i] ^= res[arrLen - i - 1];
        }

        bool carry = false;
        
        for (int i = 0; i<arrLen; ++i) {
            if (i != arrLen - 1) {
                if (carry) {
                    if (res[i] == 1) {
                        res[i] = 0;
                        continue;
                    } else {
                        res[i] = 1;
                        carry = false;
                    }
                }

                if (res[i] == 1 && res[i+1] == 1) {
                    res[i] = -1;
                    carry = true;
                }
            } else {
                if (carry) {
                    res[i] = 0;
                    res.push_back(1);
                }
            }
        }

        cout << res.size() << '\n';

        for (auto i = res.cbegin(); i!=res.cend(); ++i) {
            cout << *i << ' ';
        }

        cout << '\n';
    }

    return 0;
}
