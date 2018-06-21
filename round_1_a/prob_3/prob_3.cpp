#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

double sum() {
    int n;
    double p;
    cin >> n >> p;

    vector<int> W(n, 0);
    vector<int> H(n, 0);
    vector<double> diag_len(n, 0);

    double sum_w_h = 0;
    double sum_diag_len = 0;

    int min_w_or_h = 0;
    int prev = -1;

    for (int j = 0; j < n; j++) {
        cin >> W[j] >> H[j];
        sum_w_h = sum_w_h + W[j] + H[j];
        diag_len[j] = sqrt(pow(W[j], 2) + pow(H[j], 2));
        sum_diag_len += diag_len[j];

        int cur = fmin(W[j], H[j]);
        if (prev > 0) {
            min_w_or_h = fmin(prev, cur);
        } else {
            min_w_or_h = cur;
        }
        prev = cur;
    }

    double cur_p = 2 * sum_w_h;
    double additional_p = 2 * sum_diag_len;
    double min_additional_p = 2 * min_w_or_h;

    // cout << p << endl;

    // cout << "D:cur_p " << cur_p << endl;
    // cout << "D:additional_p " << additional_p << endl;
    // cout << "D:min_additional_p " << min_additional_p << endl;

    if (cur_p + additional_p < p) {
        return cur_p + additional_p;
    } else if (cur_p + min_additional_p <= p) {
        return p;
    } else {
        return cur_p;
    }
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    cout << setprecision(16) << fixed;
    cout << "Case #" << i << ": " << sum() << endl;
  }

  return 0;
}