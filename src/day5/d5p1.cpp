#include <algorithm>
#include <numeric>
#include <regex>
#include <stack>
#include <deque>
#include "readInput.h"

using std::stack;
using std::deque;

int main() {

    vector<String> vs = readInput("input.txt");

    //------------------------------PARSE INPUT------------------------------//

    // stack vars
    vector<stack<char>> boxes;
    vector<stack<char>> boxes_rev;
    
    // label vars
    size_t lbl_idx = 0;
    
    // get number of stacks
    size_t vidx = 0;
    while(true){

        if (std::find(vs[vidx].begin(), vs[vidx].end(), '[') == vs[vidx].end()) {
            
            auto szit = std::find_if(vs[vidx].rbegin(), vs[vidx].rend(), [](const auto& x){ return isdigit(x); });
            int sz = stoi(String(1, *szit));
            
            boxes.resize(sz);
            boxes_rev.resize(sz);
            lbl_idx = vidx;
            break;
            
        }
        ++vidx;
    }

    // get stacks //
    vidx = 0;
    while (vidx < lbl_idx){
        size_t bidx = 1;
        for (size_t i = 0; i < boxes_rev.size(); ++i){
            char b = vs[vidx][bidx];
            if (!isspace(b)){
                boxes_rev[i].push(b);
            }
            bidx += 4;
        }
        ++vidx;
    }

   // reverse stacks //
    for (size_t i = 0; i < boxes.size(); ++i){
        while(!(boxes_rev[i].empty())){
            boxes[i].push(boxes_rev[i].top()); boxes_rev[i].pop();
        }
    }

    //---------------------------------MOVES---------------------------------//

    int moves[3];
    stack<char>* orig; 
    stack<char>* dest;
    std::deque<char>* buf = new std::deque<char>();

    // regex vars
    std::smatch m;
    std::regex rgx("move ([0-9]+) from ([0-9]+) to ([0-9]+)");

    while(vidx < vs.size()){ 

        if (std::regex_search(vs[vidx], m, rgx)) {

            // get moves, assume that moves size == 3
            for(auto it = m.begin() + 1; it < m.end(); ++it){ 
                int i = it - m.begin();
                moves[i - 1] = stoi((*it).str()); 
                };

            // exec moves
            for (size_t i = 0; i < moves[0]; ++i) {
                orig = &boxes[moves[1] - 1];
                buf->push_back(orig->top()); orig->pop();
            }

            while (!buf->empty()) {
                dest = &boxes[moves[2] - 1];
                dest->push(buf->front()); buf->pop_front();
            }
        }
        ++vidx;
    }

    // print the result
    for (size_t i = 0; i < boxes.size(); ++i){ cout << (boxes[i].top()); }
    cout << endl;

    return 0;
}