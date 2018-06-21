#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    int r, b, c;
    cin >> r >> b >> c;

    vector<int> M(c, 0);
    vector<int> S(c, 0);
    vector<int> P(c, 0);

    for (int i = 0; i < c; i++) {
        cin >> M[i] >> S[i] >> P[i];
    }

    
    
    cout << "Case #" << i << ": ";
  
  }

  return 0;
}
