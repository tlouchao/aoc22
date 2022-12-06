#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include "readInput.h"

using std::array;
using std::map;
using std::set;

int main() {

    vector<String> vs = readInput("input.txt");

    // construct alphabet map
    array<char, 26> al;
    std::iota(al.begin(), al.end(), 'a');

    array<char, 26> au;
    std::iota(au.begin(), au.end(), 'A');

    array<char, 52> akeys;
    std::copy(al.begin(), al.end(), akeys.begin());
    std::copy(au.begin(), au.end(), akeys.begin() + 26);

    map<char, int> amap;
    for (int i = 0; i < 52; ++i){ amap.insert(std::make_pair(akeys[i], i + 1)); }

    // track sum of priorities
     int acc = 0;

     // track vals per group of three
    int grpCnt = 0;
    char found = '\0';
    set<char> seen[3];

    // check groups of three
    for (const auto& s : vs){
        if (grpCnt == 0) { 
            std::for_each(s.begin(), s.end(), [&seen](const auto& x){ 
                seen[0].insert(x); }); ++grpCnt;
        } else if (grpCnt == 1) {
            std::for_each(s.begin(), s.end(), [&seen](const auto& x){ 
                if (std::find(seen[0].begin(), seen[0].end(), x) != seen[0].end()){ seen[1].insert(x); }}); ++grpCnt;
        } else if (grpCnt == 2) {
            std::for_each(s.begin(), s.end(), [&seen](const auto& x){ 
                if (std::find(seen[1].begin(), seen[1].end(), x) != seen[1].end()){ seen[2].insert(x); }}); grpCnt = 0;

            // assume 1 elem; add to sum of priorities
            found = *(seen[2].begin());
            acc += amap[found];
            
            // reset
            found = '\0';
            for (auto& t : seen) {t.clear(); }
        }
    }
    cout << acc << endl;
}