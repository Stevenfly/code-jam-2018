/* Code Jam 2018
 * Qualification Round - Trouble Sort
 * Author: Yufei Yang
 * Email: stevenwaterloo2015@gmail.com
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constants:
const string ok = "OK";

// Helpers:

vector<int> trouble_sort(vector<int> L) {
    int tmp;
    bool done = false;

    while (!done) {
        done = true;
        for (int i = 0; i < L.size() - 2; i++) {
            if (L[i] > L[i + 2]) {
                done = false;
                tmp = L[i];
                L[i] = L[i + 2];
                L[i + 2] = tmp;
            }
        }
    }

    return L;
}

int check_non_decreasing(vector<int> L) {
    int prev = -1;
    for (int i = 0; i < L.size(); i++) {
        if (prev > L[i]) return i - 1;
        prev = L[i];
    }
    return -1;
}

void printCase(int num, int status) {
    cout << "Case #" << num << ": ";

    if (status < 0) cout << ok << endl;
    else cout << status << endl;
}

// main
int main() {
    int num_of_tests;
    cin >> num_of_tests;

    for (int i = 0; i < num_of_tests; i++) {
        int num_of_ints;
        cin >> num_of_ints;

        int num;
        vector<int> L;

        for (int j = 0; j < num_of_ints; j++) {
            cin >> num;
            L.emplace_back(num);
        }

        L = trouble_sort(L);

        int status = check_non_decreasing(L);

        printCase(i + 1, status);
    }
}
