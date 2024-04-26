#include <iostream>
#include <utility>
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

int addNum(int n, int indx, vector<pair<int, bool>> (&freq)[]) {
    bool found = false;
    for (int i = sizeof(int)*8 - 1; i >= 0; --i) {
        if (pow(2, i) <= n) {
            if (!found) {
                freq[i].push_back(make_pair(indx, true));
                found = true;
            } else {
                freq[i].push_back(make_pair(indx, false));
            }
            
            n -= pow(2, i);
        }
    }

    return 0;
}

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c < cases; ++c) {
        int nums;
        cin >> nums;

        int count = 0;

        int prev = 0;
        int prevs[nums];
        vector<pair<int, bool>> freq[sizeof(int) * 8];
       
        for (int i = 0; i<nums; ++i) {
            prevs[i] = 0;
        }

        for (int n = 0; n < nums; ++n) {
            int num;
            cin >> num;

            addNum(num, n, freq);   
            for (int i = sizeof(int)*8 - 1; i >= 0; --i) {
                if ((int(pow(2, i)) & num) != 0) {//there's a bit there
                    //cout << "NUMBER: " << i << ' ' << num << endl;

                    if (!(freq[i].empty())) {
                        //cout << "HEARE" << endl;
                        for (auto p = freq[i].rbegin(); p != freq[i].rend(); ++p) {
                            //cout << (*p).first << ' ' << ((*p).second == true) << endl;
                            if ((*p).first == 1 && (n == 2)) {
                                cout << "FAIL CASE" << endl;
                            }

                            if ((*p).second == true && (int(pow(2, i)) & (prevs[(*p).first] ^ prev)) != 0) { //also a bit on the previous combinations
                                cout << (*(p - 1)).first << ' ' << (*p).first << ' ' << n << endl;
                                if (((p - 1)) != freq[i].rend()) {
                                    count += (*p).first - (*(p - 1)).first; //add the difference
                                } else {
                                    ++count;
                                }
                            }
                        }
                    }
                }    
            }

            prev ^= num;
            prevs[n] = prev;
        }

        for (int i = 0; i<sizeof(int) * 8; ++i) {
            for (auto j : freq[i]) {
                //cout << j.first << j.second << endl;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
