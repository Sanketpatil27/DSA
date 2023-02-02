#include<iostream>
#include<unordered_map>

// search insert and delete:    time: O(1) on average
// but in map they are :        time: O(logn)

using namespace std;

int main() {

    unordered_map<string, int> m;

    m["string"] = 23;           // first is key & second is value
    m["str"] = 25;
    m.insert({"gtr", 45});      // to insert pairs

    // i will iterate over m, & store pairs from m 
    // any pairs can get first

    for(auto i: m) {
        cout << i.first << " " << i.second << endl;         
    }

    return 0;
}