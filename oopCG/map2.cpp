#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> myMap; // Map with integer keys and string values

    int key;
    // string value;

    // Inserting pairs into the map
    myMap.insert(make_pair(1, "One"));
    myMap.insert(make_pair(2, "Two"));
    myMap.insert(make_pair(3, "Three"));
    myMap.insert(make_pair(4, "Four"));
    myMap.insert(make_pair(5, "Five"));

    // Printing all pairs in the map
    cout << "Pairs in the map:" << endl;
    for ( auto &pair : myMap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Getting user input to print a specific pair
    cout << "\nEnter a key to print its corresponding pair: ";
    cin >> key;

    auto it = myMap.find(key); // Find the key in the map
    if (it != myMap.end()) {
        cout << "Pair: " << it->first << " => " << it->second << endl;
    } else {
        cout << "Key not found in the map." << endl;
    }

    return 0;
}
