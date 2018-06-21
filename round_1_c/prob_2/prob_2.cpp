#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <math.h>
using namespace std;

const int sold = 1;
const int not_sold = 0;


template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}





int main() {
    bool done, finished;
    int t, n, d, d_i;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> n;
        done = false;

        vector<int> flavours(n, not_sold);
        // vector<pair <int, int>> flavours_count;
        map<int, int> flavours_count;

        for (int j = 0; j < n; j++) {
            // pair <int,int> def (j, 0);
            // flavours_count.push_back(def);
            flavours_count[j] = 0;
        }

        while (!done) {
            if (n == 0) {
                done = true;
                break;
            }

            cin >> d;

            finished = false;

            set<int> ds;

            for (int j = 0; j < d; j++) {
                cin >> d_i;
                ds.insert(d_i);
                flavours_count[d_i]++;
            }

            multimap<int, int> dst = flip_map(flavours_count);

            // for (pair<int, int> p: dst) {
            //     cout << p.first << " " << p.second << endl;
            // }

            for (pair<int, int> p: dst) {
                if (ds.find(p.second) != ds.end() && !finished && flavours[p.second] == not_sold) {
                    cout << p.second << endl;

                    finished = true;
                    flavours[p.second] = sold;
                }
            }

            // for (int j = 0; j < d; j++) {
            //     cin >> d_i;
            //     flavours_count[d_i]++;

            //     if (!finished && flavours[d_i] == not_sold) {
            //         cout << d_i << endl;

            //         finished = true;
            //         flavours[d_i] = sold;
            //     }
            // }
            
            if (!finished) {
                cout << -1 << endl;
            } 

            n--;
        }
    }

    return 0;
}
