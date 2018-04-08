/* Code Jam 2018
 * Qualification Round - Go, Gopher!
 * Author: Yufei Yang
 * Email: stevenwaterloo2015@gmail.com
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constants:
const int num_row = 5;
const int num_col = 4;
const int unprepared = 0;
const int prepared = 1;

// Variables:
vector<vector<int> > orchard(num_row, vector<int>(num_col, unprepared));

// Helpers:
bool is_rec_prepared() {
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            if (orchard[i][j] == unprepared) return false;
        }
    }
    return true;
}

// main
int main() {
    bool done;
    int t, a, x, y;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> a;
        done = false;

        while (!is_rec_prepared() && !done) {
            for (int j = 1; j < 3; j++) {
                for (int k = 1; k < 4; k++) {
                    if (!done) {
                        if (is_rec_prepared()) done = true;
                        else {
                            cout << j + 1 << " " << k + 1 << endl;
                            // flush stdout
                            cin >> x >> y;
                            if (x <= 0 || y <= 0) done = true;
                            else orchard[x - 1][y - 1] = prepared;
                        }
                    }
                }
            }
        }   
    }
    return 0;
}



