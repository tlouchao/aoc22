#include <algorithm>
#include <numeric>
#include <regex>
#include <stack>
#include "readInput.h"

using std::stack;

int main() {

    vector<String> vs = readInput("input.txt");

    //------------------------------PARSE INPUT------------------------------//

    // stack var
    vector<stack<char>> boxes;

    // label var
    int lbl_idx = 0; int vidx = 0;
    
    // get number of stacks
    while(true){

        if (std::find(vs[vidx].begin(), vs[vidx].end(), '[') == vs[vidx].end()) { 

            auto szit = std::find_if(vs[vidx].rbegin(), vs[vidx].rend(), [](const auto& x){ return isdigit(x); });
            int sz = stoi(String(1, *szit));

            boxes.resize(sz);
            lbl_idx = vidx;
            break;
        }
        ++vidx;
    }
    vidx -= 1;

    // get stacks //
    while (vidx >= 0){

        size_t bidx = 1;

        for (size_t i = 0; i < boxes.size(); ++i){
            char b = vs[vidx][bidx];
            if (!isspace(b)){ boxes[i].push(b); }
            bidx += 4;
        }
        --vidx;
    }

    // seek label
    vidx = lbl_idx;

    //---------------------------------MOVES---------------------------------//

    int moves[3];
    stack<char>* orig; 
    stack<char>* dest;
    stack<char>* buf = new stack<char>();

    // regex vars
    std::smatch m;
    std::regex rgx("move ([0-9]+) from ([0-9]+) to ([0-9]+)");

    while(vidx < vs.size()){ 

        if (std::regex_search(vs[vidx], m, rgx)) {

            // get moves and ignore first match which is entire string
            for(auto it = m.begin() + 1; it < m.end(); ++it){ 
                int i = it - m.begin();
                moves[i - 1] = stoi((*it).str()); 
                };

            // exec moves
            for (size_t i = 0; i < moves[0]; ++i) {
                orig = &boxes[moves[1] - 1];
                buf->push(orig->top()); orig->pop();
            }

            while (!buf->empty()) {
                dest = &boxes[moves[2] - 1];
                dest->push(buf->top()); buf->pop();
            }
        }
        ++vidx;
    }

    // print the result
    for (size_t i = 0; i < boxes.size(); ++i){ cout << (boxes[i].top()); }
    cout << endl;

    return 0;
}