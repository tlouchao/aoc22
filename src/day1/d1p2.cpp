#include <algorithm>
#include <numeric>
#include "readInput.h"

int main() {

    vector<String> vs = readInput("input.txt");
    
    // sum calories
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
    
    // get top three
    vector<int> trois(3);
    for (int i = 0; i < 3; ++i){

        auto iiter = std::max_element(cals.begin(), cals.end());

        // add to result
        int val = *iiter;
        trois.push_back(val);

        // remove from original vec
        int idx = std::distance(cals.begin(), iiter);
        cals.erase(cals.begin() + idx);
    }

    cout << std::accumulate(trois.begin(), trois.end(), 0) << endl;
    return 0;

}