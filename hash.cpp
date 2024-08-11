# include <vector>
# include <string>
// here we will use a header file for hash table that will map the key to the values 
# include<unordered_map>

using std :: vector;
using std :: string;
using std :: unordered_map;

int main() {

    // lets initialize a vector of strings
    vector<string> names = {"alice", "brad", "collin", "brad", "dylan", "kim"};
    // we will initialize an empty unordered map names countMap
    unordered_map<string, int> countMap;

    // we will pass by reference here  for each name in names
    for (string& name: names) {
        // first we check if the name is not in the countMap
        if (countMap.count(name) == 0) {
            countMap[name] = 1;
        }
        // if the name is already there then we increment the value
        else {
            countMap[name] ++;
        }
    }

    return 0;
}
