// Name:Shubham Nikumbh
// Roll:22569


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    typedef map<string, int> mapType;
    mapType populationMap;

    populationMap.insert(make_pair("Maharashtra", 7026357));
    populationMap.insert(make_pair("Rajasthan", 6578936));
    populationMap.insert(make_pair("Karnataka", 6678993));
    populationMap.insert(make_pair("Punjab", 5789032));
    populationMap.insert(make_pair("West Bengal", 6676291));

    mapType::iterator iter;

    cout << "========Population of states in India==========\n";
    cout << "\nSize of populationMap: " << populationMap.size() << "\n";

    string state_name;
    cout << "\nEnter name of the state: ";
    cin >> state_name;

    iter = populationMap.find(state_name);
    if (iter != populationMap.end()) {
        cout << state_name << "'s population is " << iter->second << endl;
    } else {
        cout << "Population data for " << state_name << " is not found." << endl;
    }

    return 0;
}

