#ifndef READINPUT_H
#define READINPUT_H
#define FMT_HEADER_ONLY

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fmt/core.h> 

using std::cout; 
using std::cerr;
using std::endl;
using std::getline;
using std::vector;
using String = std::string;

vector<String> readInput(const String& fname) {
    vector<String> vs;
    std::ifstream fs;
    fs.open(fname);
    if (fs.is_open()){
        String tmp;
        while (getline(fs, tmp)){
            vs.push_back(tmp);
        }
        fs.close();
    } else {
        cerr << fmt::format("File \"{}\" not found\n", fname);
    }
    return vs;
}

#endif