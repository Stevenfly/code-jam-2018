#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

const string impossible = "-";

void printResult(int case_num, string result) {
    cout << "Case #" << case_num << ": " << result << endl;
}

void case1(set<char> set1, set<char> set2, set<string> tiles, int i) {
    for (char c1: set1) {
        string str;
        str.push_back(c1);
        for (char c2: set2) {
            str.push_back(c2);
            // cout << str << endl;
            if (tiles.find(str) == tiles.end()) {

                printResult(i, str);
                return;
            }
            str.pop_back();
        }
    }

    printResult(i, impossible);
}

int main() {
  int t, n, l;
  string word;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    cin >> n >> l;

    set<string> tiles;
    vector<set<char>> sets(l, set<char>());

    for (int j = 0; j < n; j++) {
        cin >> word;
        tiles.insert(word);

        for (int k = 0; k < l; k++) {
            sets[k].insert(word[k]);
        }
    }

    if (l <= 1 || n <= 1) {
        printResult(i, impossible);
    } else {
        // for (int m = 0; m < l; l++) {
        //     set<char> set = sets[m];
        //     for (char c: set) {
                
        //     }
        //     for (int n = 0; n < set.size(); n++) {

        //     }
        // }





        // printResult(i, "");
        // for (int k = 0; k < l; k++) {
        //     set<char> s = sets[k];
        //     for (char c: s) {
        //         cout << c << " ";
        //     }
        //     cout << endl;
        // }

        set<char> set1 = sets[0];
        set<char> set2 = sets[1];

        case1(set1, set2, tiles, i);
    }
  }

  return 0;
}
