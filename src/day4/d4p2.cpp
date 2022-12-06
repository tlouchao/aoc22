#include <regex>
#include <utility>
#include "readInput.h"

int main() {

    vector<String> vs = readInput("input.txt");

    int acc = 0;
    std::pair<int, int> r1;
    std::pair<int, int> r2;
    std::vector<int> rtmp;

    std::regex rgx("([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)");
    std::smatch m;

    for (const auto& s : vs){
        if(std::regex_search(s, m, rgx)) {

            // ignore first match which is entire string
            std::for_each(m.begin() + 1, m.end(), [&rtmp](const auto& x) { rtmp.push_back(stoi(x.str())); });
            r1.first = rtmp[0]; r1.second = rtmp[1];
            r2.first = rtmp[2]; r2.second = rtmp[3];
            
            // compare ranges
            if ((r2.first <= r1.second) && 
                (r2.second >= r1.first)){ 
                acc += 1; 
            }
        }
        rtmp.clear();
    }

    cout << acc << endl;
    return 0;

}