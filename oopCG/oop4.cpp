//Name:Rohit Waghmode
//Roll:22517
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Create an output file and write information to it
    ofstream outputFile("output.txt");
    
    if (!outputFile.is_open()) {
        cerr << "Error opening the file for writing!" << endl;
        return 1;
    }

    // Writing information to the file
    outputFile << "Hello, this is some information written to the file.\n";
    outputFile << "This is another line in the file.\n";
    outputFile << "And one more line for demonstration.\n";

    // Close the output file
    outputFile.close();

    // Open the file as an input file and read the information
    ifstream inputFile("output.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Error opening the file for reading!" << endl;
        return 1;
    }

    cout << "Reading information from the file:\n";

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // Close the input file
    inputFile.close();

    return 0;
}

