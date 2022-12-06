#include <algorithm>
#include <numeric>
#include "readInput.h"

int main() {

    vector<String> vs = readInput("input.txt");
    
    vector<int> cals; 
    vector<int> tmp;
    for (const auto& s : vs){
        if (s.empty()){
            cals.push_back(std::accumulate(tmp.begin(), tmp.end(), 0));
            tmp.clear();
        } else {
            tmp.push_back(stoi(s));
            if (&s == &vs.back()){ // remember to push last element
                cals.push_back(std::accumulate(tmp.begin(), tmp.end(), 0));
                tmp.clear();
            }
        }
    }

    // get max
    auto mx = *std::max_element(cals.begin(), cals.end());
    cout << mx << endl;

    return 0;
}