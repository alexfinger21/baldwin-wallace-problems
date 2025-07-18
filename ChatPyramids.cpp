#include <iostream>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c<cases; ++c) {
        int sentences;
        cin >> sentences;

        string lastPyramid = "";
        int pSize = 0;
        int lastP = 0;
        bool isPyramid = false;

        //cout << "SENTENCES: " << sentences << endl;

        for (int s = 0; s<sentences; ++s) {
            string sen;
            cin >> sen;

            if (!isPyramid) {
                int underscoreC = 1;
                string lastWord = "";

                for (int i = 0; i<sen.size(); ++i) {
                    if (sen[i] != '_') {
                        lastWord += sen[i];
                    } else if (pSize != 0) {
                        ++underscoreC;

                        if (underscoreC > pSize + 2) {
                            lastWord = "";
                            //cout << "QUIT" << endl;
                            break;
                        }

                        if (lastWord != lastPyramid) {
                            lastWord = "";
                            //cout << "QUIT" << endl;
                            break;
                        }
                        lastWord = "";
                    } else {
                        //cout << "QUIT" << endl;
                        lastWord = "";
                        break;
                    }
                }

                //cout << "P SIZE: " << pSize << " LAST WORD: " << lastWord << endl;
                //cout << "last pyramid: " << lastPyramid << endl;

                if (pSize != 0) {

                    if (underscoreC > pSize + 2) {
                        lastWord = "";
                        //cout << "QUIT" << endl;
                    }

                    if (lastWord != lastPyramid) {
                        lastWord = "";
                        //cout << "QUIT" << endl;
                    }

                }

                if (lastWord != "" && pSize == 0) {
                    ++pSize;
                    ++lastP;
                    lastPyramid = lastWord;
                    continue;
                }

                if (lastWord == "") {
                    if (pSize >= 2 && lastP == 1) {
                        isPyramid = true;   
                    }
                    lastP = 0;
                    pSize = 0;
                    lastPyramid = "";
                    continue;
                }


                if (lastWord == lastPyramid) {
                    //cout << "here " << underscoreC << ' ' << lastP << endl;
                    if (underscoreC == lastP - 1) {
                        --lastP;

                        if (lastP == 1) {
                            if (pSize >= 2) {
                                isPyramid = true;
                            }
                        }
                    } else if (underscoreC == pSize + 1) {
                        ++pSize;
                        ++lastP;
                    } else {
                        pSize = 0;
                        lastP = 0;
                        lastPyramid = "";
                    }
                }
            }
        }
        cout << "Case " << c+1 << ": " << (isPyramid ? "PYRAMID" : "NO PYRAMID") << '\n';
    }
}
