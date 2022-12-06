#include "readInput.h"
vector<String> vs = readInput("input.txt");
int main() { // NO MAPS! //
    int acc = 0, shpPt, rndPt;
    for (const auto& s : vs){
        char o = s[0], p = s[2] - 23; shpPt = p - 64, rndPt;
        if (((o - 64) % 3) - (p - 64) == -1){ rndPt = 6; }
        else if (o == p) { rndPt = 3; }
        else if ((((o - 64) + 1) % 3) - (p - 64) == -1){ rndPt = 0; } 
        acc += shpPt + rndPt;
    } cout << acc << endl;
}