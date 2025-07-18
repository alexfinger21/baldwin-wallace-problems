#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int addNum(int n, int indx, vector<int> (&maxBits)[], vector<int> (&bits)[]) {
    bool found = false;
    int maxBit = 0;

    for (int i = sizeof(int)*8 - 1; i >= 0; --i) {
        if (pow(2, i) <= n) {
            if (!found) {
                maxBits[i].push_back(indx);
                found = true;
                maxBit = i;
            }
            bits[i].push_back(indx);
            
            n -= int(pow(2, i));
        }
    }

    return maxBit;
}

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c < cases; ++c) {
        int nums;
        cin >> nums;

        int count = 0;

        vector<int> maxBits[sizeof(int)*8];
        vector<int> totalBits[sizeof(int)*8];

        int highestBit = 0;

        for (int n = 0; n < nums; ++n) {
            int num;
            cin >> num;
            //rule: XOR of the biggest midpoint bit in the interval has to equal 0
            int maxBit = addNum(num, n, maxBits, totalBits);   

            if (maxBit > highestBit) {
                highestBit = maxBit;
            }

        }

        //cout << "HIGHEST BIT: " << highestBit << endl;

        for (int i = 0; i<=highestBit; ++i) {
            for (int maxBit : maxBits[i]) {
                if (totalBits[i].size() != 1) {
                    auto bitOrder = totalBits[i];
                    auto ind = find(bitOrder.begin(), bitOrder.end(), maxBit);
                    int center = ind - bitOrder.begin();
                    //cout << "CENTER: " << center << endl;
                    //cout << "MAX BIT: " << maxBit << endl;
                    //cout << "BIT ORDER SIZE: " << bitOrder.size() << endl;
                    //iterate left, then each right, then move one left again                    
                    int rightFirst = 0;
                    int rightSecond = 0;

                    //we need 2 different right sums because if left is even we need to balance it out with one right, which will always be the same
                    int r = center + 1;

                    for (; r < bitOrder.size() - 1; r+=2) {
                        rightFirst += bitOrder[r+1] - bitOrder[r];
                    }

                    if (r == bitOrder.size() - 1) {
                        rightFirst += nums - bitOrder[r]; //total num count - index, meaning 1 more has been subtracted, intended                  
                    }

                    r = center != 0 ? center : 1;

                    for (; r < bitOrder.size() - 1; r+=2) {
                        //cout << "hmmmmmmmmmmmmm" << endl;
                        rightSecond += bitOrder[r+1] - bitOrder[r];
                    }

                    //cout << r << endl;

                    if (r == bitOrder.size() - 1) {
                        rightSecond += nums - bitOrder[r]; //total num count - index, meaning 1 more has been subtracted, intended                  
                    }

                    //cout << "first: " << rightFirst << " second: " << rightSecond << endl;

                    if (center == 0) {
                        //cout << "CENTER IS 0 " << (bitOrder[center] + 1) *rightSecond << endl;
                        count += (bitOrder[center] + 1) * rightSecond;
                    } else { 
                        count += (center != bitOrder.size() - 1) ? rightSecond : 0; //not leftmost so the firstRight gives us some initial vals before starting to move left
                    }

                    for (int l = center; l > 0; --l) {
                        int diffL = bitOrder[l] - bitOrder[l-1];
                        //cout << "diffL: " << diffL << " Index: " << bitOrder[l] << endl;
                        if (center != bitOrder.size() - 1) {
                            //cout << "add the diffs buddy" << endl;

                            if ((center - l) % 2 == 0) {//skip first one
                                count += diffL * rightFirst; 
                            } else {
                                count += diffL * rightSecond;
                            }
                        } else {
                            if ((center - l) % 2 == 0) {
                                //cout << "just add 1 + edges " <<  1 * (nums - *ind) << endl;
                                count += 1 * (nums - *ind);
                            } else {
                                //cout << "add all the juice + edges" << endl;
                                count += (diffL - 1) * (nums - *ind);
                            }
                        }
                    } 
                }
                
                //cout << endl << "-------------" << endl << endl;
                if (i == 2) {
                    //cout << endl << "STEP 3 COUNT: " << count - 10 << endl << endl;
                }

                if (i == 1) {
                    //cout << endl << "STEP 2 COUNT: " << count - 2 << endl << endl;
                }
                if (i == 0) {
                    //cout << endl << "STEP 1 COUNT: " << count << endl << endl;
                }

            }
        }

        cout << count << '\n';
    }

    return 0;
}
                                                                                                                                                                                              
