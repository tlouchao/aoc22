#include <algorithm>
#include <queue>
#include <unordered_set>
#include "readInput.h"

using std::swap;
using std::queue;
using std::unordered_set;

int main() {

    vector<String> vs = readInput("input.txt"); String s = vs[0];

    queue<char> q, qtmp;
    unordered_set<char> st;
    int res;
    
    for (size_t i = 0; i < s.length(); ++i){
        if (q.size() == 14) { q.pop(); }
        q.push(s[i]); st.clear();
        while(!q.empty()){
            qtmp.push(q.front()); 
            st.insert(q.front()); 
            q.pop();
        }
        swap(q, qtmp);
        if (q.size() == 14 && st.size() == 14){
            res = i + 1; break;
        }
    }

    cout << res << endl;
    return 0;
}