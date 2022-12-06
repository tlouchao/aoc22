#include "readInput.h"
vector<String> vs = readInput("input.txt");
int main() { // NO MAPS! //
    int acc = 0, shpPt, rndPt;
    for (const auto& s : vs){
        char o = s[0], p = s[2];
        if(p == 'X'){ rndPt = 0; shpPt = ((((o + 2) - 'A') % 3) + 'A') - 64; } 
        else if (p == 'Y'){ rndPt = 3; shpPt = o - 64; } 
        else if (p == 'Z'){ rndPt = 6; shpPt = ((((o + 1) - 'A') % 3) + 'A') - 64; }
        acc += shpPt + rndPt;
    } cout << acc << endl;
}