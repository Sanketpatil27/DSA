#include<iostream>
#include<unordered_map>
#include<vector>


using namespace std;

// time O(n^2)
void countFreq(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        bool flag = false;      // initially false means we don't have add it before

        for (int j = 0; j < i; j++)
        {
            if(v[i] == v[j]) {
                flag = true;        // if we found it before current position, then dont print again
                break;
            }
        }

        // means we have find current elem b4 so don't need to print it again
        if(flag == true) 
            continue;
        
        // else part
        int freq = 1;       // 1 for current elem, loop starts from next elem

        for(int j = i+1; j < v.size(); j++)  {
            if(v[i] == v[j])              
                freq++;
        }

        cout << "frequency of " << v[i] << ": "  << freq << endl;
    }
}

int main() {
    vector<int> v = {10, 10, 23, 34, 10, 34, 23, 45};



    // neive approach:
    countFreq(v);


    unordered_map<int, int> freq;

    for(auto i: v) {
        freq[i]++;      // this will store i(elem) as key and increment each time as value;
    }

    cout << "Freqeuncies are: " << endl;

    for(auto i: freq)  {
        cout << i.first << ": " << i.second << endl;
    }
}