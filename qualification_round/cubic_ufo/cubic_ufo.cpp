/* Code Jam 2018
 * Qualification Round - Cubic UFO
 * Author: Yufei Yang
 * Email: stevenwaterloo2015@gmail.com
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

// Constants:
const double side_len = 1.0;
const double half_side_len = side_len / 2;

// main
int main() {
    int t;
    double a, tilted_radian, center_radian, x, y;
    
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> a;

        tilted_radian = acos(a / M_SQRT2);
        center_radian = tilted_radian + M_PI_4;

        x = cos(center_radian) * half_side_len;
        y = sin(center_radian) * half_side_len;

        cout << "Case #" << i << ":" << endl;
        cout << setprecision(16) << fixed;
        cout << x << " " << y << " 0" << endl;
        cout << -y << " " << x << " 0" << endl;
        cout << "0 0 0.5" << endl;
    }

    return 0;
}
