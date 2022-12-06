#include <algorithm>
#include <numeric>
#include <map>
#include "readInput.h"

using std::array;
using std::map;

int main() {

    vector<String> vs = readInput("input.txt");

    // construct alphabet map
    array<char, 26> atmp;
    array<char, 52> akeys;

    std::iota(atmp.begin(), atmp.end(), 'a');
    std::copy(atmp.begin(), atmp.end(), akeys.begin());
    
    std::iota(atmp.begin(), atmp.end(), 'A');
    std::copy(atmp.begin(), atmp.end(), akeys.begin() + 26);

    map<char, int> amap;
    for (size_t i = 0; i < 52; ++i){ amap.insert(std::make_pair(akeys[i], i + 1)); }

    // track sum of priorities
    int acc = 0;

    // split rucksack into two halves
    for (const auto& s : vs){

        const size_t half = s.length() / 2;
        vector<char> left(s.begin(), s.begin() + half);
        vector<char> right(s.begin() + half, s.end());
        
        std::sort(left.begin(), left.end());
        std::sort(right.begin(), right.end());

        // check if item is seen
        vector<char> fv; 
        std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(fv));
        char found = fv.at(0);
        
        acc += amap[found];
    }

    cout << acc << endl;
    return 0;

}