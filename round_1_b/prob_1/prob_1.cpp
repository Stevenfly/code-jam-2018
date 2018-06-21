#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


int calculate_rounded_percentage(vector<int>& lans, int num_people) {
    int rounded_percentage = 0;

    for (int i = 0; i < lans.size(); i++) {
        double percent_i = lans[i] / (double)num_people * 100;
        int rounded_percent_i = round(percent_i);
        rounded_percentage += rounded_percent_i;
    }

    return rounded_percentage;
}

// combinations with repetition
int max_rounded_percentage(int num_lan, int num_unrespond, vector<int>& lans, int num_people){
    int max_rounded_percentage = 0;

    num_lan--;
    vector<int> v;

    for (int i = 0; i <= num_unrespond; ++i) v.push_back(0); 

    while (true){ 
        for (int i = 0; i < num_unrespond; ++i){
            if (v[i] > num_lan){ 
                v[i + 1] += 1; 
                for (int k = i; k >= 0; --k){ 
                    v[k] = v[i + 1]; 
                } 
            } 
        } 

        if (v[num_unrespond] > 0) break;

        for (int i = 0; i < num_unrespond; ++i) lans[v[i]]++;
        max_rounded_percentage = max(max_rounded_percentage, calculate_rounded_percentage(lans, num_people));
        for (int i = 0; i < num_unrespond; ++i) lans[v[i]]--;

        v[0] += 1; 
    } 

    return max_rounded_percentage; 
} 


int main() {
  int t, n, l, c;
  int num_respond, num_unrespond, current_percent, result;

  cin >> t;

  for (int i = 1; i <= t; ++i) {
    cin >> n >> l;

    vector<int> lans(l, 0);
    num_respond = 0;

    for (int j = 0; j < l; j++) {
        cin >> c;

        lans[j] = c;
        num_respond += c;
    }

    num_unrespond = n - num_respond;

    current_percent = calculate_rounded_percentage(lans, num_people);







    for (int j = 0; j < num_unrespond; j++) {
        lans.push_back(0);
    }

    result = max_rounded_percentage(lans.size(), num_unrespond, lans, n); 

    cout << "Case #" << i << ": " << result << endl;
  }
  return 0;
}
