  
// Katie Young
// CS 325, Homework Assignment #4

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

int readLines(string dataFile);
void lineToArray(vector<int> &vect, string dataString, int length);

int main() {
    int removeFile = remove("change.txt"); // Delete output file in case program has already been run
    string data = "data.txt";
    int success = readLines(data); // Initiate program

    // Output message according to program success
    if (success == 1) {
        cout << "Change calculation complete." << endl;
    }
    else {
        cout << "Error: Failed to open file." << endl;
    }

    return 0;
}

// Reads file line by line and initiates sorting
// Returns 1 if sorting successful
// Returns 0 if file error
int readLines(string dataFile) {
    string fileLine;
    int len, c, k, n;
    vector<int> valueVector;

    ifstream inputFile(dataFile.c_str()); // Open passed file

    // If open successful, read lines
    if (inputFile.is_open()) {
        getline(inputFile, fileLine);
        
        valueVector.resize(3);

        // Convert line to vector containing c, k and n (respectively)
        lineToArray(valueVector, fileLine, 3);
        c = valueVector[0];
        k = valueVector[1];
        n = valueVector[2];

        cout << "c: " << c << " k: " << k << " n: " << n << endl;

            // // Sort vector
            // insertSort(valueVector, len);

        valueVector.clear(); // Clear vector elements

        inputFile.close(); // Close ifstream
        return 1; // Return 1 if successful
    }
    else {
        return 0; // Return 0 if unsuccessful
    }  
}

// Converts a passd string to a vector by separating integers from spaces
void lineToArray(vector<int> &vect, string dataString, int length) {
    int dataItr = 0;
    int vectorItr = 0;
    int isLength = 1;
    int dataValue = 0;
    string dataItem;

    // Iterate through string
    while ((dataItr <= dataString.length()) && (vectorItr < length)) {
        // When separator identified, convert value to integer and append to vector
        if ((dataItr == dataString.length()) || (dataString[dataItr] == ' ') && (dataString[dataItr + 1] != ' ')) {
            dataValue = atoi(dataItem.c_str()); // Convert value to integer
            vect[vectorItr] = dataValue;
            vectorItr++;
            
            dataValue = 0;
            dataItem = "";
        }
        else {
            dataItem += dataString[dataItr]; // Append character to string until separator reached
        }

        dataItr++;
    }
}