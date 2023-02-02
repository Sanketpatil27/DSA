#include<iostream>
#include<unordered_map>

using namespace std;

// time complexities:  O(1) in worst case
// begin()  
// end()
// size()
// empty() 

// time complexities:  O(1) on average
// count()
// find()
// erase()
// insert()
// at
// []

int main() {

    unordered_map<string, int> m;

    m["string"] = 23;        
    m["str"] = 25;
    m.insert({"gtr", 45});

    // find() used to search whether the *key* is present or not
    // find() reutrns an iterator 
    // if key not present then it return special iterator which is m.end()

    if(m.find("str") != m.end())
        cout << "found" << endl;
    
    auto i = m.find("str");             // i is a pointer to pair of key value
    cout << i->second ;                 // we can access the key like this

    cout << endl;

    for(auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }


    // count() used to find wheather an element is present or not like find()
    // count return either 0 (not present) or 1  (present) but return type is not boolean it's size_t

    if(m.count("gtr") > 0)
        cout << "counted" << endl;
    else
        cout << "not counted" << endl;

    // size() return number of key-value pairs
    cout << "size: " << m.size() << endl;


    // erase() used to remove key-value pair, return 1 if removed either 0 if not present
    // it can also receive iterator and delete it
    cout << m.erase("string") << endl;          // can pass only key
    m.erase(m.begin());                         // returns iterator of first pair
    m.erase(m.begin(), m.end());                // we can pass ending also, remove everything
    cout << "size: " << m.size() << endl;

    if(m.empty())
        cout << "empty" << endl;
}