#include <iostream>
#include <vector>
#include <string>
using namespace std;

const char ch_chip = '@';
const char empty = '.';

const string possible = "POSSIBLE";
const string impossible = "IMPOSSIBLE";

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    bool done = false;

    int r, c, h, v;
    cin >> r >> c >> h >> v;

    int num_chips = 0;
    int num_serves = (h + 1) * (v + 1);

    vector<vector<int>> waffle(r, vector<int>(c, 0));

    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
            char cell;
            cin >> cell;

            if (cell == ch_chip) {
                num_chips++;
                waffle[j][k] = 1;
            } 
        }
    }

    if (num_chips == 0 && !done) {
        cout << "Case #" << i << ": " << possible << endl;
        done = true;
    }

    int remainder = num_chips % num_serves;
    int chips_per_serve = num_chips / num_serves;

    if (remainder != 0 && !done) {
        cout << "Case #" << i << ": " << impossible << endl;
        done = true;
    }
    
    // Test set 1

    bool has_possible = false;

    for (int h_cut = 0; h_cut < r - 1; h_cut++) {
        for (int v_cut = 0; v_cut < c - 1; v_cut++) {

            vector<int> serves(num_serves, 0);

            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    if (j <= h_cut && k <= v_cut) {
                        if (waffle[j][k]) {
                            serves[0]++;
                        }
                    }

                    if (j <= h_cut && k > v_cut) {
                        if (waffle[j][k]) {
                            serves[1]++;
                        }
                    }

                    if (j > h_cut && k > v_cut) {
                        if (waffle[j][k]) {
                            serves[2]++;
                        }
                    }

                    if (j > h_cut && k <= v_cut) {
                        if (waffle[j][k]) {
                            serves[3]++;
                        }
                    }
                }
            }

            bool has_false = false;
            
            for (int i = 0; i < serves.size(); i++) {
                if (serves[i] != chips_per_serve) {
                    has_false = true;
                }
            }

            if (has_false == false) {
                has_possible = true;
            }
        }
    }

    if (!done) {
        if (has_possible) {
            cout << "Case #" << i << ": " << possible << endl;
        } else {
            cout << "Case #" << i << ": " << impossible << endl;
        }
    }

    // vector<int> h_cut_pos(h, 0);
    // vector<int> v_cut_pos(v, 0);

    // vector<int> waffle_h_cut_pos(r - 1, 0);
    // vector<int> waffle_v_cut_pos(c - 1, 0);

    // for (int m = 0; m < h; m++) {
    //     for (int m_cut = 0; m_cut < r - 1; m_cut++) {
    //         if (waffle_h_cut_pos[m_cut] != 1) {
    //             waffle_h_cut_pos[m_cut] = 1; // cut!
    //             h_cut_pos[m] = m_cut;


    //         }
    //     }


    //     for (int n = 0; n < v; n++) {

    //     }
    // }
  
  }

  return 0;
}
