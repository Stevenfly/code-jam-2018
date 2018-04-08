/* Code Jam 2018
 * Qualification Round - Saving The Universe Again
 * Author: Yufei Yang
 * Email: stevenwaterloo2015@gmail.com
 */

#include <iostream>
#include <string>
using namespace std;

// Constants:
const string impossible = "IMPOSSIBLE";
const char charge = 'C';
const char shoot = 'S';

// Helpers:

// count_dmg: robot_prog
// counting and return the damage robot_prog can make
int count_dmg(string robot_prog) {
    int stren = 1, dmg = 0;

    for(char& c : robot_prog) {
        if (c == charge) stren *= 2;
        if (c == shoot)  dmg += stren;
    }

    return dmg;
}

// contains_cs: robot_prog
// check if robot_prog containes adjacent 'CS', return boolean
bool contains_cs(string robot_prog) {
    if (robot_prog.size() < 2) return false;
    
    char prev_c;

    for(char& c : robot_prog) {
        if (prev_c && prev_c == charge && c == shoot) return true;
        prev_c = c;
    }

    return false;
}

// swap_last_cs: robot_prog
// swap the last 'CS' in robot_prog, it is assumed that contains_cs
string swap_last_cs(string robot_prog) {
    for (int i = robot_prog.size() - 1; i > 0; i--) {
        int last_i = i, sec_last_i = i - 1;

        if (robot_prog[sec_last_i] == charge && robot_prog[last_i] == shoot) {
            robot_prog[sec_last_i] = shoot;
            robot_prog[last_i] = charge;
            break;
        }
    }

    return robot_prog;
}

// printCase: num is_possible num_of_hacks
// output based on rules described
void printCase(int num, bool is_possible, int num_of_hacks) {
    cout << "Case #" << num << ": ";

    if (is_possible) cout << num_of_hacks << endl;
    else cout << impossible << endl;
}

// main
int main() {
    int num_of_tests;
    cin >> num_of_tests;

    for (int i = 0; i < num_of_tests; i++) {
        int max_shield;
        string robot_prog;
        cin >> max_shield >> robot_prog;

        bool is_possible = true;
        int num_of_hacks = 0;
        int dmg = count_dmg(robot_prog);

        while (dmg > max_shield) {
            num_of_hacks++; // the President hacks!

            /* To achieve minimum num of hacks:
             * - only need to swap "CS"
             * - we swap last appearance of "CS" 
             */
            if (contains_cs(robot_prog)) {
                robot_prog = swap_last_cs(robot_prog);
                dmg = count_dmg(robot_prog);
            } else {
                is_possible = false;
                break;
            }
        }

        printCase(i + 1, is_possible, num_of_hacks);
    }
}
